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
int k = 0;
int l = 0;
k = i * j;
l = j * i;


for (i = 0; i <= 9; i++)
{
for (j = 0; j <= 9; j++)
{
if (i == j)
{
continue;
}
else if (k != l || k == l)
{
putchar('0' + i);
putchar('0' + j);
putchar(',');
putchar(' ');
}
else
{
continue;
}
}
}
putchar('\n');
return (0);
}
