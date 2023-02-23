#include <ctype.h>
#include <stdio.h>
#include "main.h"

/**
 * print_numbers- multiplies two numbers
 * Description: program will assign a random number to the variable n each time
 * it is executed.
 *
 * Return: returns the answer
 */

void print_numbers(void)
{
	int i = 48;

	while (i < 58)
	{
		_putchar(i);
		i++;
	}
	_putchar('\n');
}

