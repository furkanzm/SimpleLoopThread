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
void SystemInterface::addOutput(SystemInterface *System)
{
	outq.push_back(System);
}

int SystemInterface::Loop(NOTIFY_TYPE)
{
	auto basePtr = std::shared_ptr<Buf>();
	auto derivedPtr = std::shared_ptr<StringBuf>();
	basePtr = std::static_pointer_cast<Buf>(derivedPtr);
	auto downcastedPtr = std::dynamic_pointer_cast<StringBuf>(basePtr);

	if (downcastedPtr == std::shared_ptr<StringBuf>()) {
		while (!buffer.empty()) {
			auto buf = process(buffer.front());
			for (int i = 0; i < outq.size(); ++i) {
				std::unique_lock<std::mutex> lck(mutex_);
				std::shared_ptr<Buf> bf = std::make_shared<StringBuf>(buf);
				outq[i]->add(bf);
			}
			buffer.pop();
		}
	}
	return 0;
}
