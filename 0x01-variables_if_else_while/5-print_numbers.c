#include <stdio.h>

/**
 * main - print all the integers in base 10
 *
 * Return: 0 (Success)
 */
int main(void)
{
	int c;

	for (c = 0; c < 10; c++)
	{
		printf("%d", c);
	}
	putchar('\n');
	return (0);
}
