#include "search_algos.h"

/**
* binary_search_ - Uses binary search approach
* to find an element in a an array.
*
* @arr: The array to to iterate through.
* @left: The left side of the array.
* @right: The right side of the array.
* @value: The value to look for in the array.
* Description: Returns the index of the value
* to search for in an array
* Return: Return the index of the element in
* the array
*/


int binary_search_(int arr[], int left, int right, int value)
{

	size_t mid;
	int i;

	while (left <= right)
	{
		mid = left + (right - left) / 2;

		printf("Searching in array: ");
		for (i = left; i <= right; i++)
		{
			printf("%d", arr[i]);
			if (i < right)
			{
				printf(", ");
			}
		}
		printf("\n");

		if (arr[mid] == value)
		{
			return (mid);
		}
		else if (arr[mid] < value)
		{
			left = mid + 1;
		} else
		{
			right = mid - 1;
		}
	}

	return (-1);
}

/**
* exponential_search - Uses the exponential search algorithm to search
* for an element in an array,
*
* @array: The array to iterate through.
* @size: The size of the array.
* @value: The value to search for.
*
* Return: The index of the the value if found else
* -1.
*/

int exponential_search(int *array, size_t size, int value)
{
	size_t range, low, high;

	if (!array || size == 0)
		return (-1);

	if (array[0] == value)
		return (0);

	range = 1;
	while (range < size && array[range] <= value)
	{
		printf("Value checked array[%lu] = [%d]\n", range, array[range]);
		range *= 2;
	}

	low = range / 2;
	high = range < size ? range : size - 1;

	printf("Value found between indexes [%ld] and [%ld]\n", low, high);

	if (low <= high)
	{
		return (binary_search_(array, low, high, value));
	}

	return (-1);
}
