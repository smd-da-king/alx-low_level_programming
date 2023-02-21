#include <main.h>

/**
* _islower - Entry point
* @c: The integer value
*Return: 1 is True; 0 is false
*/

int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c <= 'A' && c <= 'B'))
{
return (1);
}
else
{
return (0);
}
}

