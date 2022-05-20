#ifndef SYSTEMINTERFACE_H
#define SYSTEMINTERFACE_H

#include "simpleloopthread.h"   
#include <iostream>
#include <queue>

class SystemInterface : public SimpleLoopThread
{
public:
	SystemInterface();
	~SystemInterface();
	void add(const std::string &buf);
	void addOutput(SystemInterface *System);
	virtual std::string process(const std::string &) = 0;
	// calısacak fonksıyon processı cagıracak processten gelen verıyı out lara
	// gonderecek
private:
	int Loop(NOTIFY_TYPE nt) override;
	std::vector<SystemInterface *> out;
	std::queue<std::string> buffer;
	std::mutex mutex_;
};

class SystemUpper : public SystemInterface
{
public:
	SystemUpper();
	~SystemUpper();
	std::string process(const std::string &buf) override;

};

class SystemLower : public SystemInterface
{
public:
	SystemLower();
	~SystemLower();
	std::string process(const std::string &buf) override;
};
#endif // SYSTEMINTERFACE_H
