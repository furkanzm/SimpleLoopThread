#ifndef SYSTEMINTERFACE_H
#define SYSTEMINTERFACE_H

#include "buf.h"
#include "intbuf.h"
#include "simpleloopthread.h"
#include "stringbuf.h"
#include <iostream>
#include <math.h>
#include <queue>

class SystemInterface : public SimpleLoopThread
{
public:
	SystemInterface();
	~SystemInterface();
	void add(std::shared_ptr<Buf> buf);
	void addOutput(std::shared_ptr<SystemInterface>);
	virtual std::shared_ptr<Buf> process(std::shared_ptr<Buf>) = 0;

private:
	std::vector<std::shared_ptr<SystemInterface>> outq;
	std::queue<std::shared_ptr<Buf>> buffer;
	int Loop(NOTIFY_TYPE nt) override;
	std::mutex mutex_;
};
#endif // SYSTEMINTERFACE_H
