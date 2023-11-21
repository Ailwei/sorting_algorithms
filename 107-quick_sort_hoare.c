#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/**
 * hoare_partition - Hoare partition scheme
 * @array: Array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 * Return: Partition index
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int x = low - 1, z = high + 1;
	size_t k;

	while (1)
	{
		do {
			x++;
		} while (array[x] < pivot);

		do {
			z--;
		} while (array[z] > pivot);

		if (x >= z)
			return z;

		
		swap(&array[x], &array[z]);
		printf("Swap: ");
		for (k = 0; k < size; k++)
		{
			printf("%d", array[k]);
			if (k < size - 1)
				printf(", ");
		}
		printf("\n");
	}
}

/**
 * quick_sort - Recursive QuickSort function using Hoare partition scheme
 * @array: Array to be sorted
 * @low: Starting index of the array
 * @high: Ending index of the array
 * @size: Size of the array
 */
void quick_sort2(int *array, int lower, int higher, size_t size)
{
    if (lower < higher)
    {
        int partition_index = hoare_partition(array, lower, higher, size);

        
        quick_sort2(array, lower, partition_index, size);
        quick_sort2(array, partition_index + 1, higher, size);
    }
}

/**
 * quick_sort_hoare - Initiates QuickSort with Hoare partition scheme
 * @array: Array to be sorted
 * @size: Size of the array
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quick_sort2(array, 0, size - 1, size);
}
