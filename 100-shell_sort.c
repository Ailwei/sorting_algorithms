#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 * algorithm with Knuth sequence.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t space = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (space < size / 3)
		space = space * 3 + 1;
	while (space > 0)
	{
		/*printf("%lu\n", (unsigned long)space);*/
		for (i = space; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= space && array[j - space] > temp; j -= space)
			{
				array[j] = array[j - space];
			}
			array[j] = temp;
		}
		space = (space - 1) / 3;
		print_array(array, size);
	}
}
