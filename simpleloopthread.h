#ifndef SIMPLELOOPTHREAD_H
#define SIMPLELOOPTHREAD_H

#include <atomic>
#include <condition_variable>
#include <functional>
#include <mutex>
#include <string>
#include <thread>


class SimpleLoopThread
{
public:
    enum NOTIFY_TYPE { NOTIFIED = 0, TIMEOUT };
    SimpleLoopThread(const std::string &tname = "SLT");
    ~SimpleLoopThread();
    SimpleLoopThread(const SimpleLoopThread &) = delete;
    void Start();
    void Stop();
    void Wait();
    void Notify();
    bool IsRunning() const;
    void SetFunc(std::function<int(NOTIFY_TYPE)> c);
    void SetTimeout(int ms); // 0->wait forever, >0 -> wait timeout
    virtual int Loop(NOTIFY_TYPE nt) = 0;
    int GetResCode() const;
private:
    void funcLoop();
    std::mutex loopMtx;
    std::condition_variable loopCv;
    int timeout = 0;
    std::atomic_bool thrRun = false;
    std::thread loopThr;
    std::function<int(NOTIFY_TYPE)> cb;
    std::string thrName;
    std::atomic_int resCode;
};

#endif // SIMPLELOOPTHREAD_H
