#include "systemupper.h"

SystemUpper::SystemUpper()
{
}

SystemUpper::~SystemUpper()
{
}

std::string SystemUpper::process(std::shared_ptr<Buf> buf)
{
	std::string val(buf->data(), buf->data() + buf->size());
    
	std::transform(val.begin(), val.begin() + 8, val.begin(),
				   ::toupper);
    std::cout << "data: " <<val << std::endl;
	return val;
}
