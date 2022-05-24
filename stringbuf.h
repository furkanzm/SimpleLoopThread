#ifndef STRINGBUF_H
#define STRINGBUF_H

#include "buf.h"
class StringBuf : public Buf
{
public:
	StringBuf(const std::string &strstr);
	uint8_t *data() override;
	size_t size() override;
	std::string toString();

private:
	std::string stringBuffer;
};
#endif // STRINGBUF_H
