#include "System1.h"
#include "System2.h"
#include "simpleloopthread.h"
#include "systeminterface.h"
#include <iostream>
#include <pipeline.h>

#define shortSleep std::this_thread::sleep_for(std::chrono::milliseconds(1500))
#define longSleep  std::this_thread::sleep_for(std::chrono::milliseconds(3000))

class dum : public SystemInterface
{
public:
	std::shared_ptr<Buf> process(std::shared_ptr<Buf> buf) override
	{
		auto downcastedPtr = std::dynamic_pointer_cast<StringBuf>(buf);
		std::cout << downcastedPtr->toString() << std::endl;

		return std::make_shared<StringBuf>("*");
	}
};

int main()
{
	PipeLine pipe;
	std::shared_ptr<SystemInterface> system1 = std::make_shared<System1>();
	std::shared_ptr<SystemInterface> system2 = std::make_shared<System2>();
	std::shared_ptr<SystemInterface> dm = std::make_shared<dum>();
	pipe.addSystem(system1);
	pipe.addSystem(system2);
	pipe.addSystem(dm);
	pipe.Start();

	shortSleep;
	std::cout << "\n";
	std::shared_ptr<Buf> strbuf1 =
		std::make_shared<StringBuf>("fffffffffffff");
	system1->add(strbuf1);
	shortSleep;

	std::shared_ptr<Buf> strbuf2 = std::make_shared<StringBuf>("cppprimer");
	system1->add(strbuf2);
	shortSleep;

	std::shared_ptr<Buf> strbuf3 =
		std::make_shared<StringBuf>("FuRkAnUzUm");
	system1->add(strbuf3);
	shortSleep;

	std::shared_ptr<Buf> strbuf4 =
		std::make_shared<StringBuf>("yirmidortMayıs");
	system1->add(strbuf4);
    shortSleep;
    
    std::shared_ptr<Buf> strbuf5 =
        std::make_shared<StringBuf>("aaaaaAAAAAaaaaa");
    system1->add(strbuf5);
	longSleep;
	return 0;
}
