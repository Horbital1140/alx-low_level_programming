#include <stdio.h>
/**
 * main - a program that print the lower case alphbet
 * Return: 0 (success)
 */
int main(void)
{
	char c = 'z';

	while (c >= 'a')
	{
		putchar(c);
		c--;
	}
	putchar('\n');
	return (0);
}
