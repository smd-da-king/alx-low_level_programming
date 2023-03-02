#include "main.h"

/**
*_strcat - function concatenate two strings
* @dest: first variable
* @src: second variable
* Return: dest - success
*/
char *_strcat(char *dest, char *src)
{
int lent = 0, i;

while (dest[lent])
lent++;
for (i = 0; src[i] != 0; i++)
{
dest[lent] = src[i];
lent += 1;
}
dest[lent] = '\0';
return (dest);
}
