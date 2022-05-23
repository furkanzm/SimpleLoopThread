#ifndef SYSTEMUPPER_H
#define SYSTEMUPPER_H

#include "systeminterface.h"

class SystemUpper : public SystemInterface
{
public:
	SystemUpper();
	~SystemUpper();
	std::string process(std::shared_ptr<Buf>buf) override;
};

#endif // SystemUpper_H
