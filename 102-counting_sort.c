#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max_value, i;

	for (max_value = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	return (max_value);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, *sorted_array, max_value, z;

	if (array == NULL || size < 2)
		return;

	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
		return;
	max_value = get_max(array, size);
	count_array = malloc(sizeof(int) * (max_value + 1));
	if (count_array == NULL)
	{
		free(sorted_array);
		return;
	}

	for (z = 0; z < (max_value + 1); z++)
		count_array[z] = 0;
	for (z = 0; z < (int)size; z++)
		count_array[array[z]] += 1;
	for (z = 0; z < (max_value + 1); z++)
		count_array[z] += count_array[z - 1];
	print_array(count_array, max_value + 1);

	for (z = 0; z < (int)size; z++)
	{
		sorted_array[count_array[array[z]] - 1] = array[z];
		count_array[array[z]] -= 1;
	}

	for (z = 0; z < (int)size; z++)
		array[z] = sorted_array[z];

	free(sorted_array);
	free(count_array);
}
