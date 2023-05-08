#include "main.h"

/**
 * create_file - Create_file.
 * @filename: pointing_to the name of the file_to_create.
 * @text_content: pointing_to a string to write to_the_file.
 *
 * Return: If_function fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int a, c, le_n = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (le_n = 0; text_content[le_n];)
			le_n++;
	}

	a = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	c = write(a, text_content, le_n);

	if (a == -1 || c == -1)
		return (-1);

	close(a);

	return (1);
}
