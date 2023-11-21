#include "sort.h"

/**
 * sift_down - Perform the sift-down operation in the heap sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 * @root: The root index of the heap.
 * @end: The end index of the heap.
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t max_child, child, swap;

	while ((root * 2 + 1) <= end)
	{
		max_child = root * 2 + 1;
		child = max_child + 1;

		if (child <= end && array[child] > array[max_child])
			max_child = child;

		if (array[root] < array[max_child])
		{
			swap = array[root];
			array[root] = array[max_child];
			array[max_child] = swap;

			print_array(array, size);
			root = max_child;
		}
		else
		{
			break;
		}
	}
}

/**
 * heapify - Build a max heap from the array.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void heapify(int *array, size_t size)
{
	ssize_t begin = (size - 2) / 2;

	while (begin >= 0)
	{
		sift_down(array, size, begin, size - 1);
		begin--;
	}
}

/**
 * heap_sort - Sort an array of integers in ascending order using Heap sort.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t finish;

	if (array == NULL || size < 2)
		return;

	heapify(array, size);

	finish = size - 1;
	while (finish > 0)
	{
		int swap = array[finish];
		array[finish] = array[0];
		array[0] = swap;

		print_array(array, size);
		finish--;

		sift_down(array, size, 0, finish);
	}
}

