#include "main.h"

/**
 * print_line- multiplies two numbers
 * @n: accepts an integer
 * Description: program will assign a random number to the variable n each time
 * it is executed.
 *
 * Return: returns the answer
 */

void print_line(int n)
{
	while (n > 0)
	{
		_putchar('_');
		n--;
	}

	if (n <= 0)
		_putchar('\n');
}
