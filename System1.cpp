#include "System1.h"

System1::System1()
{
}

System1::~System1()
{
}

std::shared_ptr<Buf> System1::process(std::shared_ptr<Buf> buf)
{
	std::shared_ptr<Buf> localPtr;
	auto downcastedPtr = std::dynamic_pointer_cast<StringBuf>(buf);
	std::string stringBuf = downcastedPtr->toString();
	std::transform(stringBuf.begin() + 7, stringBuf.end(),
				   stringBuf.begin() + 7, ::tolower);
	localPtr = std::make_shared<StringBuf>(stringBuf);

	return localPtr;
}
