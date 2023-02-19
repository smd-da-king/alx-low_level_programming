#include <stdio.h>

/**
 * main - print all the possible combinations of two digits
 *
 * Return: (0) success
 */

int main(void)
{
int i = 0;
int j = 0;

for (i = 0; i <= 8; i++)
{
for (j = i + 1; j < 10; j++)
{
putchar('0' + i);
putchar('0' + j);
if (i < 8)
{
putchar(',');
putchar(' ');
}
}
}
putchar('\n');
return (0);
}
