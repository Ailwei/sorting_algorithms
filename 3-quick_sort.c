#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Implements the Lomuto partition scheme.
 * @array: Array to be partitioned.
 * @_low: Starting index of the partition.
 * @_high: Ending index of the partition.
 * @_size: Size of the array.
 *
 * Return: Index of the pivot element.
 */
int lomuto_partition(int *array, int _low, int _high, size_t _size)
{
	int pivot = array[_high];
	int i = _low - 1, j;

	for (j = _low; j <= _high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, _size);
		}
	}
	swap(&array[i + 1], &array[_high]);
	if (i + 1 != _high)
		print_array(array, _size);

	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function to implement Quick Sort.
 * @array: Array to be sorted.
 * @low: Starting index of the partition.
 * @hi: Ending index of the partition.
 * @size: Size of the array.
 */
void quick_sort_recursive(int *array, int low, int hi, size_t size)
{
	int Pivot;

	if (low < hi)
	{
		Pivot = lomuto_partition(array, low, hi, size);

		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, hi, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *              the Quick sort algorithm with Lomuto partition scheme.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

