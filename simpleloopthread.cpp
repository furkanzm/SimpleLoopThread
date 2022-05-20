#include "simpleloopthread.h"
#include <bits/stdc++.h>
#ifdef __linux__
#include <sys/prctl.h>
#endif
SimpleLoopThread::SimpleLoopThread(const std::string &tname)
	: thrName(tname), resCode(INT_MAX)
{
}

SimpleLoopThread::~SimpleLoopThread()
{
	Stop();
}

void SimpleLoopThread::Start()
{
	thrRun.store(true);
	if (!loopThr.joinable()) {
		std::cout << thrName << " will start";
		loopThr = std::thread(&SimpleLoopThread::funcLoop, this);
	}
}

void SimpleLoopThread::Stop()
{
	thrRun.store(false);
	if (loopThr.joinable()) {
		loopCv.notify_all();
		loopThr.join();
	}
}

void SimpleLoopThread::Wait()
{
	if (loopThr.joinable())
		loopThr.join();
}

void SimpleLoopThread::Notify()
{
	loopCv.notify_all();
}

bool SimpleLoopThread::IsRunning() const
{
	return loopThr.joinable();
}

void SimpleLoopThread::SetFunc(std::function<int(NOTIFY_TYPE)> c)
{
	if (loopThr.joinable()) {
		Stop();
	}
	cb = c;
}

void SimpleLoopThread::SetTimeout(int ms)
{
	timeout = ms;
}

int SimpleLoopThread::Loop(NOTIFY_TYPE nt)
{
	if (cb)
		return cb(nt);
	return INT_MIN;
}

int SimpleLoopThread::GetResCode() const
{
	return resCode.load();
}

void SimpleLoopThread::funcLoop()
{
	std::cout << thrName << " started";
#ifdef __linux__
	prctl(PR_SET_NAME, thrName.data(), 0, 0, 0);
#endif
	while (thrRun.load()) {
		std::cv_status notified;
		{
			std::unique_lock<std::mutex> lck(loopMtx);
			if (timeout == 0) {
				loopCv.wait(lck);
			} else if (timeout > 0) {
				notified =
					loopCv.wait_for(lck, std::chrono::milliseconds(timeout));
			}
			if (!thrRun.load())
				break;
		}
		int res =
			Loop((notified == std::cv_status::no_timeout ? NOTIFIED : TIMEOUT));
		resCode.store(res);
		if (res != 0) {
			std::cout << thrName
					  << " will be stopped because of res code: " << res;
			break;
		}
	}
	std::cout << thrName << " will stop";
}
