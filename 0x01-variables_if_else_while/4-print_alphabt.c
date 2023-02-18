#include <stdio.h>

/**
 * main - print alphabet a to z without q and e
 *
 * Return: 0 (Success)
 */


int main(void)

{
	char c;

for (c = 'a'; c <= 'z'; ++c)
	{
		if (c == q || c == e)
		{
		continue;
		}
		putchar(c);

	}
		putchar('\n');
return (0);
}

