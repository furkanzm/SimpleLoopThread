#include "buf.h"
#include "simpleloopthread.h"
#include "systeminterface.h"
#include "systemlower.h"
#include "systemupper.h"
#include <iostream>
class dum : public SystemInterface
{
public:
	dum() {}
	std::string process(std::shared_ptr<Buf> buf)
	{
		std::cout << "size: " << buf->size() << std::endl;
		return " ";
	}
};

int main()
{
	SystemUpper upper;
	SystemLower lower;
	dum dm;
	//	upper.addOutput(&lower);
	//	lower.addOutput(&dm);
	lower.addOutput(&upper);
	upper.addOutput(&dm);
	dm.Start();
	// std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	upper.Start();
	lower.Start();
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "\n";

	std::shared_ptr<Buf> bf = std::make_shared<StringBuf>("FuRkAnUzUmADaSd");
	lower.add(bf);
	std::this_thread::sleep_for(std::chrono::milliseconds(1200));

	std::shared_ptr<Buf> bg =
		std::make_shared<StringBuf>("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	lower.add(bg);
	std::this_thread::sleep_for(std::chrono::milliseconds(1200));

	std::shared_ptr<Buf> bl = std::make_shared<StringBuf>("YiRmIUcMaYıS2022");
	lower.add(bl);
	std::this_thread::sleep_for(std::chrono::milliseconds(1200));

	std::shared_ptr<Buf> bc =
		std::make_shared<StringBuf>("FFffffffffffFFFFFFffff");
	lower.add(bc);
	//	std::shared_ptr<Buf> bf(new StringBuf("ffffffffff"));
	//    upper.add(bf);
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	return 0;
}
