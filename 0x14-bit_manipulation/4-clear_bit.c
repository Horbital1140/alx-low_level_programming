#include "main.h"

/**
 * clear_bit - change_number to binary
 * @n: numb_change
 * @index: numb_to_change
 *
 * Return:int
 */


int clear_bit(unsigned long int *n, unsigned int index)
{
	/* this code Check the index validity */
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	/* below line of code Clear the bit at index by shifting 1 to the left and negating */
	*n &= ~(1ul << index);

	return (1);
}
