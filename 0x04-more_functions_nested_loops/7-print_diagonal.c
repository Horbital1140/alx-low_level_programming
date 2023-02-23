#include "main.h"

/**
 * print_diagonal- multiplies two numbers
 * @n: accepts an integer
 * Description: program will assign a random number to the variable n each time
 * it is executed.
 *
 * Return: returns the answer
 */

void print_diagonal(int n)
{
	int line = 0;
	int spaces;

	if (n > 0)
	{
		while (line < n)
		{
			for (spaces = 0; spaces < line; spaces++)
			{
				_putchar(' ');
			}
			_putchar('\\');
			_putchar('\n');
			line++;
		}
	}
	else
	{
		_putchar('\n');
	}
}
