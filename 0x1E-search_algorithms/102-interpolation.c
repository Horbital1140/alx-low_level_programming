#include "search_algos.h"

/**
* search_helper - Helper function for
* interpolation search.
* @arr: The array to search through.
* @low: The lower bound of the array.
* @high: The upper bound of the array.
* @value: The value to search for.
*
* Return: The index of the value if found, -1
*/

int search_helper(int *arr, int low, int high, int value)
{
	int position;

	if (low <= high && value >= arr[low] && value <= arr[high])
	{
		position = low + (((double)(high - low) /
		(arr[high] - arr[low])) * (value - arr[low]));

		printf("Value checked array[%d] = [%d]\n", position, arr[position]);

		if (arr[position] == value)
			return (position);

	/*
	* We move either left or right
	* depending on the value of the
	* current position.
	*/

		if (arr[position] < value)
			return (search_helper(arr, position + 1, high, value));

		return (search_helper(arr, low, position - 1, value));
	}
	printf("Value checked array[%d] is out of range\n", high);
	return (-1);
}


/**
* interpolation_search - Uses the interpolation
* search algorithm to search for a value.
*
* @array: The array to iterate through.
* @size: The size of the array.
* @value: The value to search for.
*
* Return: The index of the the value if found, -1
* otherwise.
*/


int interpolation_search(int *array, size_t size, int value)
{
	if (!array || !value)
		return (-1);

	if (size == 1)
		return (0);

	return (search_helper(array, 0, size - 1, value));
}
