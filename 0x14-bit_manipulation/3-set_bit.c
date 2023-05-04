#include "main.h"

/**
 * set_bit - change_number to binary
 * @n: numb_change
 * @index: numb_change
 *
 * Return:int
 */


int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int metty = 1UL << index;

	if (index >= (sizeof(unsigned long int) * 5))
		return (-1);

	*n |= metty;

	return (1);
}
