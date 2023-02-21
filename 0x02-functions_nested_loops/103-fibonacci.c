#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers, starting with 1 and 2
 *
 * Return: Always 0.
 */

int main(void)
{
	long int sum, value;
	long int first, second;

	sum = 0;
	value = 0;
	first = 0;
	second = 1;

	while (value < 4000000)
	{
		value = first + second;
		first = second;
		second = value;
		if (value % 2 == 0)
			sum = sum + value;
	}
	printf("%li\n", sum);

	return (0);
}

