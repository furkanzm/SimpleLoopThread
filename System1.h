#ifndef SYSTEM1_H
#define SYSTEM1_H

#include "systeminterface.h"

class System1 : public SystemInterface
{
public:
	System1();
	~System1();
	std::shared_ptr<Buf> process(std::shared_ptr<Buf>) override;
};
#endif //SYSTEM1_H
