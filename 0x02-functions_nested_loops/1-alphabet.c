#include <stdio.h>

/**
 *alpha - writes the character c to stdout
 *function @c: The character to print
 *
 * Return: (0) On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

void alpha(void)
{
int i;

for (i = 'a'; i <= 'z'; i++)
{
putchar(i);
}
}
/**
 *main - writes the character c to stdout
 *function @c: The character to print
 *
 * Return: (0) On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int main(void)
{
alpha();
putchar('\n');
return (0);
}
