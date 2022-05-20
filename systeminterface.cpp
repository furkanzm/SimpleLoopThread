#include "systeminterface.h"

SystemInterface::SystemInterface()
{
}

SystemInterface::~SystemInterface()
{
}

void SystemInterface::add(const std::string &buf)
{
    buffer.push(buf);
    Notify();
}
void SystemInterface::addOutput(SystemInterface *System)
{
    out.push_back(System);
}

int SystemInterface::Loop(NOTIFY_TYPE)
{
    std::unique_lock<std::mutex> lck(mutex_);
    while (!buffer.empty()) {
        std::string buf = process(buffer.front());
        for (int i = 0; i < out.size(); ++i) {
            out[i]->add(buf);
        }
        buffer.pop();
    }
    return 0;
}

SystemUpper::SystemUpper()
{
}

SystemUpper::~SystemUpper()
{
}
std::string SystemUpper::process(const std::string &buf)
{
    std::string strstr = buf;
    std::transform(strstr.begin(), strstr.begin() + 3, strstr.begin(), ::toupper);
    return strstr;
}

SystemLower::SystemLower()
{
}

SystemLower::~SystemLower()
{
    
}

std::string SystemLower::process(const std::string &buf)
{
    
    std::string strstr = buf;
    std::transform(strstr.begin() + 3, strstr.end(), strstr.begin() + 3, ::tolower);
    return strstr;
}

