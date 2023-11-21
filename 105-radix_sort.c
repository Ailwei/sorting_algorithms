#include "sort.h"

int find_maximum(int *array, int size);
void perform_radix_counting_sort(int *arr, size_t size, int sig, int *temp_buffer);
void radix_sort(int *arr, size_t size);

/**
 * find_max - Find the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int find_maximum(int *array, int size)
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
 * perform_radix_counting_sort - Sort the significant digits of an array of integers
 *                               in ascending order using the counting sort algorithm.
 * @arr: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @temp_buffer: A buffer to store the sorted array.
 */
void perform_radix_counting_sort(int *arr, size_t size, int sig, int *temp_buffer)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(arr[i] / sig) % 10] += 1;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size; i > 0; i--)
	{
		temp_buffer[count[(arr[i - 1] / sig) % 10] - 1] = arr[i - 1];
		count[(arr[i - 1] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		arr[i] = temp_buffer[i];
}

/**
 * perform_radix_sort - Sort an array of integers in ascending
 *                     order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max_value, sig_digit, *temp_buffer;

	if (array == NULL || size < 2)
		return;

	temp_buffer = malloc(sizeof(int) * size);
	if (temp_buffer == NULL)
		return;

	max_value = find_maximum(array, size);
	for (sig_digit = 1; max_value / sig_digit > 0; sig_digit *= 10)
	{
		perform_radix_counting_sort(array, size, sig_digit, temp_buffer);
		print_array(array, size);
	}

	free(temp_buffer);
}

