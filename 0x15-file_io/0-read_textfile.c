#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - text file will be read, it will be printed in posix stdio.
 *  @filename: it point to the file
 * @letters: Total number of letters the
 *           function should read_print.
 *
 * Return: If the function fails or filename is NULL - 0.
 *         O/w - the actual number of bytes the function can read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t a;
	ssize_t b;
	ssize_t c;
	char *butter;

	if (filename == NULL)
		return (0);

	butter = malloc(sizeof(char) * letters);
	if (butter == NULL)
		return (0);

	a = open(filename, O_RDONLY);
	b = read(a, butter, letters);
	c = write(STDOUT_FILENO, butter, b);

	if (a == -1 || b == -1 || c == -1 || c != b)
	{
		free(butter);
		return (0);
	}

	free(butter);
	close(a);

	return (c);
}

