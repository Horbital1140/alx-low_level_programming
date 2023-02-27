#include "main.h"

/**
 * _puts - Write a function that prints a string, followed by a new line, to
 * stdout.
 *
 * @str: This is my input string
 *
 */

void _puts(char *str)
{
	int a;

	for (a = 0; (s[a]) != '\0'; a++)
	{
		_putchar(s[a]);
	}
	_putchar('\n');
}
