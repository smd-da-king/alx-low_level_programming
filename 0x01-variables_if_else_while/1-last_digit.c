#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/* more headers goes there */

/* betty style doc for function main goes there */
/**
 * main - print
 *
 * Return: 0 (Success)
 */
int main(void)
{
	int n, m;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	m = n % 10;
		printf("Last digit of %d is ",n);
		if (m > 5)
		{
			printf("and is greater than 5\n");		
		}
		else if (m == 0)
		{
			printf("and is 0\n");
		}
		else if (m > 6 && m < 0)
		{
			printf("and is less than 6 and not 0\n");
		}
		else
		{
			printf("end");
		}
	/* your code goes there */
	return (0);
}
