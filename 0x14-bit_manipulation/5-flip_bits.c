#include "main.h"

/**
 * flip_bits - change_number to binary
 * @n: numb_change
 * @m: numb_to_change
 *
 * Return:int
 */


unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_output = n ^ m;
	unsigned int note = 0;

	while (xor_output)
	{
		if (xor_output & 1)
			note++;
		xor_output >>= 1;
	}

	return (note);
}
