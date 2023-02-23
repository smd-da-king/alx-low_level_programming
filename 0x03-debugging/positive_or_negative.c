#include <stdio.h>
#include "main"
/**
*positive_or_negative - print check -+
*
*Return: 0
*/

void positive_or_negative(int n)
{
if (n > 0)
{
	printf("%d is positive\n", n);
}
else if (n < 0)
{
	printf("%d is negative\n", n);
}
else
{
	printf("%d is zero\n", n);
}
}
