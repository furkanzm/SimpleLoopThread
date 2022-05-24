#include "System2.h"

System2::System2()
{
}

System2::~System2()
{
}

std::shared_ptr<Buf> System2::process(std::shared_ptr<Buf> buf)
{
	std::shared_ptr<Buf> localPtr;
	auto downcastedPtr = std::dynamic_pointer_cast<StringBuf>(buf);
	std::string stringBuf = downcastedPtr->toString();
	std::transform(stringBuf.begin(), stringBuf.begin() + 7, stringBuf.begin(),
				   ::toupper);
	localPtr = std::make_shared<StringBuf>(stringBuf);

	return localPtr;
}
