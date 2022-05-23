#ifndef SYSTEMLOWER_H
#define SYSTEMLOWER_H

#include "systeminterface.h"

class SystemLower : public SystemInterface
{
public:
	SystemLower();
    ~SystemLower();
	std::string process(std::shared_ptr<Buf>buf) override;
};

#endif // SYSTEMLOWER_H
