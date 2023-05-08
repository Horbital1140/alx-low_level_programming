#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile - reads_text_file and prints it to the POSIX stdout
 * @filename: pointer_name of file_to read
 * @letters: number of letters to read_and_print
 *
 * Return: actual number of letters_read_and printed; or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fil_e;
	ssize_t r_bytes, w_bytes;
	char *buffer;

	if (filename == NULL)
		return (0);

	fil_e = open(filename, O_RDONLY);
	if (fil_e == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fil_e);
		return (0);
	}

	r_bytes = read(fil_e, buffer, letters);
	if (r_bytes == -1)
	{
		close(fil_e);
		free(buffer);
		return (0);
	}

	w_bytes = write(STDOUT_FILENO, buffer, r_bytes);
	if (w_bytes == -1 || (size_t) w_bytes != (size_t) r_bytes)
	{
		close(fil_e);
		free(buffer);
		return (0);
	}

	close(fil_e);
	free(buffer);

	return (r_bytes);
}
