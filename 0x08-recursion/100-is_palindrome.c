#include "main.h"
#include <string.h>

/**
* is_palindrome - function name
* s: var4
* i: var1
* length: var2
* flag: var3
* @s: varb4
* Return: 0- fail and 1- success
*/
int is_palindrome(char *s)
{
int i, length;
int flag = 0;

length = strlen(s);
for (i = 0; i < length; i++)
{
if (s[i] != s[length - i - 1])
{
flag = 1;
break;
}
}
if (flag)
{
return (0);
}
else
{
return (1);
}
}
