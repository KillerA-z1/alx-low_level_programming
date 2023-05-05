#include "main.h"



int get_endianness(void)
{
	unsigned short int i = 1;
	char *ptr = (char *)&i;

	if (*ptr)
		return (1);
	else
		return (0);
}
