#include <stdio.h>

/**
* main - print 9 times
*
*Return: 0 Success
*
*/

int main(void)
{
int i, j, k;

for (i = 0; i <= 9; i++)
{
for (j = 0; j <= 9; j++)
{
k = i * j;
putchar(k + '0');
}
}
return (0);
}
