#include <stdio.h>

/**
 * main - print all the possible combinations of a single digit number
 *
 * Return: (0) Success;
 */

int main(void)
{
	int x;

	for (x = 0; x < 10; x++)
	{
		putchar(x + '0');
		if (x < 9)
		{
			putchar(',');
			putchar(' ');
		}

	}
	putchar('\n');
	return (0);

}
