#include "main.h"

/**
 * append_text_to_file - join_text at the file_end.
 * @filename: pointing to the file_name
 * @text_content: string to join to the file_end
 *
 * Return: If the function fails or filename is NULL - -1.
 *         If the file does not exist the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int a, c, le_n = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (le_n = 0; text_content[le_n];)
			le_n++;
	}

	a = open(filename, O_WRONLY | O_APPEND);
	c = write(a, text_content, le_n);

	if (a == -1 || c == -1)
		return (-1);

	close(a);

	return (1);
}
