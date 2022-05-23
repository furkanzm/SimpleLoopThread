#ifndef SYSTEMINTERFACE_H
#define SYSTEMINTERFACE_H

#include "buf.h"
#include "simpleloopthread.h"
#include "stringbuf.h"
#include <iostream>
#include <atomic>
#include <queue>

class SystemInterface : public SimpleLoopThread
{
public:
	SystemInterface();
	~SystemInterface();
	void add(std::shared_ptr<Buf> buf);
	void addOutput(SystemInterface *System);
	virtual std::string process(std::shared_ptr<Buf>) = 0;

private:
	int Loop(NOTIFY_TYPE nt) override;
	std::vector<SystemInterface *> outq;
	std::queue<std::shared_ptr<Buf>> buffer;
	std::mutex mutex_;
	bool flag;
};

#endif // SYSTEMINTERFACE_H
