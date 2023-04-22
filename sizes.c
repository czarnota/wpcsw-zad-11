#include <stdio.h>
#include <stddef.h>

#define TYPES \
	F(char) \
	F(short) \
	F(int) \
	F(long) \
	F(long long) \
	F(float) \
	F(double) \
	F(unsigned char) \
	F(unsigned short) \
	F(unsigned int) \
	F(unsigned long) \
	F(unsigned long long) \
	F(void *) \
	F(size_t) \

void sizes(void)
{
#define F(x) printf("sizeof(%s) is %zu\n", #x, sizeof(x));
	TYPES
#undef F
}
