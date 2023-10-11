i#include "search_algos.h"
#include <math.h>

/**
* jump_search - Uses the jump search algorithm to search
* for an element in an array,
*
* @array: The array to iterate through.
* @size: The size of the array.
* @value: The value to search for.
*
* Return: The index of the the value if found, -1 otherwise.
*/


int jump_search(int *array, size_t size, int value)
{
	size_t step, prev_step;

	if (!array || !value)
		return (-1);

	prev_step = 0;
	step = sqrt(size - 1);
	printf("Value checked array[%ld] = [%d]\n", prev_step, array[prev_step]);

	while (array[step] < value)
	{
		if (prev_step >= size - 1)
		{
			printf("Value found between indexes [%ld] and [%ld]\n", prev_step,
			step);
			printf("Value checked array[%ld] = [%d]\n", prev_step, array[size - 1]);
			return (-1);

		}

		printf("Value checked array[%ld] = [%d]\n", step, array[step]);

		prev_step = step;
		step = step + sqrt(size - 1);
	}

	printf("Value found between indexes [%ld] and [%ld]\n", prev_step, step);

	for (; prev_step < size; prev_step++)
	{
		printf("Value checked array[%ld] = [%d]\n", prev_step, array[prev_step]);

		if (array[prev_step] == value)
			return (prev_step);
	}

	printf("Value checked array[%ld] = [%d]\n", prev_step, array[size - 1]);
	return (-1);

}
