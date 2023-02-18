#include <stdio.h>

/**
 * main - print low case alphabet using putchar
 *
 * Return: (0) Success
 */
int main(void)
{
	char c;

	for (c = 'z'; c >= 'a'; c--)
	{
		putchar(c);
	}

	putchar('\n');
return (0);
}
