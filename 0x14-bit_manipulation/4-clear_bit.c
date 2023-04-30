#include "main.h"

/**
 * clear_bit - Entry point
 * Description: Sets the value of a bit to 0 at a given index.
 * @n: Pointer to the number to be changed
 * @index: The index, starting from 0 of the bit you want to set
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
unsigned long int mask1;
if (index >= (sizeof(unsigned long int) * 8))
{
return (-1);
}
	mask1 = ~(1 << index);
	*n &= mask1;

	return (1);
}
