#include "main.h"
#include <string.h>

/**
 * _strncat -> function to append some charx
 * @dest: var 1
 * @src: var 2
 * @n: var 3 
 * Return: string
 */
char *_strncat(char *dest, char *src, int n)
{
	strncat(dest, src, n);
	return (dest);
}
