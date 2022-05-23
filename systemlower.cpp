#include "systemlower.h"

SystemLower::SystemLower()
{
}

SystemLower::~SystemLower()
{
}

std::string SystemLower::process(std::shared_ptr<Buf> buf)
{
    
    std::string val(buf->data(), buf->data() + buf->size());
	std::transform(val.begin()+8, val.end(),
				   val.begin()+8, ::tolower);
	return val;
}
