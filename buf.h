#ifndef BUF_H
#define BUF_H
#include "simpleloopthread.h"
#include <iostream>
class Buf
{
public:
	Buf();
	virtual uint8_t *data() = 0;
	virtual size_t size() = 0;
};

#endif // BUF_H
