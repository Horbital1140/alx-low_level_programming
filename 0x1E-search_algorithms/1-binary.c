#include "search_algos.h"


/**
* binary_search - Uses binary search approach
* to find an element in a an array.
*
* @array: The array to to iterate through.
* @size: The length of the array.
* @value: The value to look for in the array.
*
* Description: Returns the index of the value
* to search for in an array
* Return: Return the index of the element in
* the array
*/
int binary_search(int *array, size_t size, int value)
{
	size_t low, high, mid, index;

	if (!array || !value)
		return (-1);

	if (size == 1)
		return (0);


	low = 0;
	high = size - 1;

	while (low <= high)
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

	/* Check if the mid is same as value */
		if (array[mid] == value)
			return (mid);

		else if (array[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return (-1);
}

