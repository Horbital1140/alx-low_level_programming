#include <stdio.h>
#include "main.h"

/**
 * get_bit - change number to binary
 * @n: number_to_change
 * @index: number to change
 *
 * Return:int
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);
	return ((n >> index) & 1);
}
