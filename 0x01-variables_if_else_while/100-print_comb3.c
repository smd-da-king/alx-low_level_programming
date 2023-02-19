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
int k = j * i;
int l = i * j;

for (i = 0; i <= 9; i++)
{
for (j = 0; j <= 9; j++)
{
if (i == j)
{
continue;
}
else if (k != l || k == l )
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
