#include <stdio.h>
#include "main.h"
/**
 * print_binary - change  number to binary
 * @n: no to change
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	if (n > 1)
		print_binary(n >> 1);
	putchar((n & 1) ? '1' : '0');
}
