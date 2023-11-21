#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using
 *                  the Selection Sort algorithm.
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void selection_sort(int *array, size_t size)
{
	size_t z, j, min_idx;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (z = 0; z < size - 1; z++)
	{
		min_idx = z;

		for (j = z + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != z)
		{
			temp = array[z];
			array[z] = array[min_idx];
			array[min_idx] = temp;

			print_array(array, size);
		}
	}
}
