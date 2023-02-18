#include <stdio.h>

/**
 * main - print all the possible combinations of two digits
 *
 * Return: (0) success
 */

int main(void)
{
int i;
int j;

for (i = '0'; i <= '9'; i++)
{
for (j = '0'; j <= '9'; j++)
{
if (i == j)
{
continue;
}

putchar(i);
putchar(j);
putchar(',');
putchar(' ');
}
}
putchar('\n');
return (0);
}
