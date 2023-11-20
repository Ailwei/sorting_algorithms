#include "sort.h"


/**
 * merge_subarray - Sort a subarray of integers.
 * @subarray: A subarray of an array of integers to sort.
 * @buffer: A buffer to store the sorted subarray.
 * @first: The front index of the array.
 * @mid: The middle index of the array.
 * @last: The back index of the array.
 */
void merge_subarray(int *subarray, int *buffer, size_t first, size_t mid,
		size_t last)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarray + first, mid - first);

	printf("[right]: ");
	print_array(subarray + mid, last - mid);

	for (i = first, j = mid; i < mid && j < last; k++)
		buffer[k] = (subarray[i] < subarray[j]) ? subarray[i++] : subarray[j++];
	for (; i < mid; i++)
		buffer[k++] = subarray[i];
	for (; j < last; j++)
		buffer[k++] = subarray[j];
	for (i = first, k = 0; i < last; i++)
		subarray[i] = buffer[k++];

	printf("[Done]: ");
	print_array(subarray + first, last - first);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarray: A subarray of an array of integers to sort.
 * @buffer: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_sort_recursive(int *subarray, int *buffer, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarray, buffer, front, mid);
		merge_sort_recursive(subarray, buffer, mid, back);
		merge_subarray(subarray, buffer, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, 0, size);

	free(buffer);
}

