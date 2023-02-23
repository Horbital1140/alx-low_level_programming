#include <ctype.h>
#include <stdio.h>

/**
 * _isupper- determine if a character is upper
 *@c: accepts an integer
 * Description: program will assign a random number to the variable n each time
 * it is executed.
 *
 * Return: Always 0 (Success)
 */

int _isupper(int c)
{
	if (isupper(c))
		return (1);
	return (0);
}
