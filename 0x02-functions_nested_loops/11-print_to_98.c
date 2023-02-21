#include <stdio.h>

/**
 * print_to_98 - get the absolute value of an integer
 * @n: accept an integer
 *
 * Return: 1 or 0
*/

void print_to_98(int n)
{
	if (n < 98)
	{
		while (n < 98)
		{
			printf("%d, ", n);
			n++;
		}
	}
	else if (n > 98)
	{
		while (n > 98)
		{
			printf("%d, ", n);
			n--;
		}
	}
	printf("98\n");
}
