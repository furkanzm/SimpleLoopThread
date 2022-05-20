#include "simpleloopthread.h"
#include "systeminterface.h"
#include <iostream>
class dum : public SystemInterface
{
public:
	dum() {}
	std::string process(const std::string &buf)
	{
		std::cout << buf << std::endl;
		return " ";
	}
};

int main()
{

	SystemUpper upper;
	SystemLower lower;
	dum dm;
	upper.addOutput(&lower);
	lower.addOutput(&dm);
	dm.Start();
	upper.Start();
	lower.Start();

	std::this_thread::sleep_for(std::chrono::milliseconds(400));
	upper.add("\nFURKAN uzum");
	std::this_thread::sleep_for(std::chrono::milliseconds(400));
    upper.add("aBCdefGehASdSd");
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    upper.add("hllLLh");
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    upper.add("aNkArA CankAYA");
	upper.add("aNkArA CankAYA");
	std::this_thread::sleep_for(std::chrono::milliseconds(400));
	upper.add("YIRMI MAyıs");
	std::this_thread::sleep_for(std::chrono::milliseconds(400));
	upper.add("SpaRSe TecH");
	std::this_thread::sleep_for(std::chrono::milliseconds(1200));
	return 0;
}
