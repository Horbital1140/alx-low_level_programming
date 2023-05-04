#include "main.h"

/**
 * get_endianness - endianness_system
 *
 * Return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	unsigned int ade = 1;
	char *gbola = (char *)&ade;

	if (*gbola)
		return (1);
	else
		return (0);
}
