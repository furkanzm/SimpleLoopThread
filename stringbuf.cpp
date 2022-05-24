#include "stringbuf.h"

StringBuf::StringBuf(const std::string &strstr)
{
	stringBuffer = strstr;
}

std::string StringBuf::toString()
{
	return stringBuffer;
}

uint8_t *StringBuf::data()
{
	return (std::uint8_t *)stringBuffer.data();
}

size_t StringBuf::size()
{
	return stringBuffer.size();
}
