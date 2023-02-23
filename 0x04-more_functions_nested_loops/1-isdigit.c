#include <ctype.h>
#include <stdio.h>

/**
 * _isdigit- determine if a character is upper
 *@c: accepts an integer
 * Description: program will assign a random number to the variable n each time
 * it is executed.
 *
 * Return: Always 0 (Success)
 */

int _isdigit(int c)
{
	if (isdigit(c))
		return (1);
	return (0);
}
