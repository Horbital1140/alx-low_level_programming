#include "main.h"

/**
 * _strlen - returns_the length of a string
 * @s: string to_evaluate
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i;

	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}
