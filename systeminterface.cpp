#include "systeminterface.h"

SystemInterface::SystemInterface()
{
}

SystemInterface::~SystemInterface()
{
}

void SystemInterface::add(std::shared_ptr<Buf> buf)
{
	buffer.push(buf);
	Notify();
}

void SystemInterface::addOutput(std::shared_ptr<SystemInterface> System)
{
	outq.push_back(System);
}

int SystemInterface::Loop(NOTIFY_TYPE)
{

	while (!buffer.empty()) {

		std::unique_lock<std::mutex> lck(mutex_);
		std::shared_ptr<Buf> buf = buffer.front();
		auto bufR = process(buf);
		for (int i = 0; i < outq.size(); ++i) {
			outq[i]->add(bufR);
		}
		buffer.pop();
	}
	return 0;
}
