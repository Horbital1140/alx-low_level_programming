#include "search_algos.h"

/**
* advanced_binary_recursive - Recursive binary search.
*
* @array: The array to search in.
* @low: The low index of the current search range.
* @high: The high index of the current search range.
* @value: The value to search for.
*
* Return: The index of the value in the array or -1 if not found.
*/
int advanced_binary_recursive(int *array, size_t low, size_t high, int value)
{
	size_t mid, index;

	if (low <= high)
	{

		printf("Searching in array: ");
		for (index = low; index <= high; index++)
		{
			printf("%d", array[index]);
			if (index < high)
				printf(", ");
		}
		printf("\n");

		mid = (low + high) / 2;

		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			return (advanced_binary_recursive(array, mid + 1, high, value));
		else
			return (advanced_binary_recursive(array, low, mid - 1, value));
	}

	return (-1);
}

/**
* advanced_binary - Wrapper function.
*
* @array: The array to search in.
* @size: The size of the array.
* @value: The value to search for.
*
* Return: The index of the value in the array or -1 if not found.
*/
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
