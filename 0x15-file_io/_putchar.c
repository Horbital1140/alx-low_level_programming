#include <unistd.h>

/**
 * _putchar - charater c is written in stdout
 * @c: character that need to be printed
 *
 * Return: successful 1.
 * On error, return -1, and errno
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
