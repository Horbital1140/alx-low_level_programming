#include <stdio.h>
/**
 * main -  a program that prints the alphabet in lowercase, and then in uppercase
 * Rturn: 0
 */
int main(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
		putchar(letter);

	for (letter = 'A'; letter <= 'z'; letter++)
		putchar(letter);
	putchar('\n');

	return (0);
}
