#ifndef SYSTEM2_H
#define SYSTEM2_H

#include "systeminterface.h"

class System2 : public SystemInterface
{
public:
	System2();
	~System2();
	std::shared_ptr<Buf> process(std::shared_ptr<Buf>) override;
};

#endif // SYSTEM2_H
