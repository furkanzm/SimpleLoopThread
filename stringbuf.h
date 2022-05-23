#ifndef STRINGBUF_H
#define STRINGBUF_H

#include "buf.h"
class StringBuf : public Buf
{
public:
    StringBuf();
	uint8_t *data() override;
	size_t size() override;
	StringBuf(const std::string &strstr);
    std::string rndm ();
private:
	std::string stringBuffer;
};
#endif // STRINGBUF_H
