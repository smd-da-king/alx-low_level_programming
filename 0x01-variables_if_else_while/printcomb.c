#include <stdio.h>

/**
*main - print two numbers
*
*Return: 0 (Success)
*/

int main(void)

{




int i;

for (i = 1; i <= 89; i++)
{
if (i == 10 || i == 11 || i == 21 || i == 22)
{
continue;
}
if (i != 89)
{
putchar(i + '0');
putchar(',');
putchar(' ');
}
putchar('\n');
return (0);
}
}
