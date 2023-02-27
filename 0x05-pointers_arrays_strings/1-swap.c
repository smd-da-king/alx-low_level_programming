#include "main.h"

/**
* swap_int - swapping int 
* @a: integer a
* @b: integer b
*
*/

void swap_int(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}
