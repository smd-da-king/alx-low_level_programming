#include "main.h"

/**
* print_alphabet_x10 - print alphabet in lower case X 10
*
*Return: (0) Success
*/

void print_alphabet_x10(void)
{
int i, j;

for (j = 0; j < 9; j++)
{
for (i = 'a'; i <= 'z'; i++)
{
_putchar(i);
}
_putchar('\n');
}
}
