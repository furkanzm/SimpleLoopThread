#include "pipeline.h"

PipeLine::PipeLine()
{
}

void PipeLine::addSystem(std::shared_ptr<SystemInterface> System)
{
	Systems.push_back(System);
}

void PipeLine::Start()
{
	for (int i = 0; i < Systems.size(); ++i) {
        if(i != Systems.size()-1)
            Systems[i]->addOutput(Systems[i + 1]);
		Systems[i]->Start();
	}
}
