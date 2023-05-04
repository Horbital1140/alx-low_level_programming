#include <stddef.h>
#include "main.h"

/**
 * binary_to_uint - the link list loop should be find
 * @b: it is pointing to string of 0 and 1 character
 *
 * Return: converted number, or 0 if
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int output = 0;
	int check = 0;

	if (b == NULL)
		return (0);


	while (b[check] != '\0')
	{
		if (b[check] == '0')
			output <<= 1;
		else if (b[check] == '1')
		{
			output <<= 1;
			output |= 1;
		}
		else
			return (0);
		check++;
	}

	return (output);
}
