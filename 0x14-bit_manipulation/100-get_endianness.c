#include "main.h"

/**
 * get_endianness - Entry point
 * Description: Checks the endianness
 * Return: 0 if big endian, 1 if little endian
 */


int get_endianness(void)
{
	unsigned int digitss = 1;
	char *data = (char *)&digitss;

	if (*data)
	{
		/* Little endian */
		return (1);
	}
	else
	{
		/* Big endian */
		return (0);
	}
}
