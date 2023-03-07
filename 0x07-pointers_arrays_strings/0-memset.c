#include "main.h"
#include <string.h>

/**
 * _memset -> this memory set funct
 * @s: string
 * @b: c charcter
 * @n: an integer
 * Return:  a string
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int c;

	for (c = 0; c < n; c++)
		s[c] = b;

	return (s);
}
