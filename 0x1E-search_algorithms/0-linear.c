#include "search_algos.h"


/**
* linear_search - Search for a value in an array
* @array: The array to search in
* @size: Size of the array or length
* @value: Value to search for.
*
* Description: Linear search algorithm
* Return: The index of the value to search for
*/

int linear_search(int *array, size_t size, int value)
{
	size_t index;

	if (!array)
		return (-1);

	for (index = 0; index < size; index++)
	{
		printf("Value checked array[%ld] = [%d]\n", index, array[index]);
		if (value == array[index])
			return (index);
	}
	return (-1);
}
