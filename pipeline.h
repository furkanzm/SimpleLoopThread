#ifndef PIPELINE_H
#define PIPELINE_H

#include "systeminterface.h"

class PipeLine
{
public:
	PipeLine();
	void addSystem(std::shared_ptr<SystemInterface> System);
	void Start();

private:
	std::vector<std::shared_ptr<SystemInterface>> Systems;
};

#endif // PIPELINE_H
