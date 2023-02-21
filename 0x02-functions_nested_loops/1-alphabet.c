#include "main.h"

/**
 *print_alphabet - writes the character c to stdout
 *function @c: The character to print
 *
 * Return: (0) On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

void print_alphabet(void)
{
int i;

for (i = 'a'; i <= 'z'; i++)
{
_putchar(i);
}
_putchar('\n');
}
