#include "main.h"

/**
*_islower - check whether integer is lowercase
* @c: The integer valu
*Return:(1) Success
*/


int _islower(int c)
{
if (c >= 'a' && c <= 'z')
{
return (1);
}
else
{
return (0);
}
}
