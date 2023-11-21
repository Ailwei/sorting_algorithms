#include "sort.h"


/**
 * print_merge - Prints information about a merging step
 * @message: The message to be printed
 * @array: The array being merged
 * @low: The starting index of the merge
 * @size: The size of the merge
 * @position: The direction of the merge (UP or DOWN)
 */

void print_merge(const char *message, int *array, size_t low, size_t size, int position)
{
    printf("%s [%lu/%lu] (%s):\n", message, size, size, position ? "UP" : "DOWN");
    print_array(array + low, size);
}

/**
 * exchange - Swaps two elements in an array
 * @arr: The array containing elements to be swapped
 * @i: Index of the first element
 * @j: Index of the second element
 */
void exchange(int *arr, size_t i, size_t j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    printf("Swap %d and %d\n", arr[i], arr[j]);
}

/**
 * bitonic_merge - Merges two halves of an array in a specific direction
 * @arr: The array to be merged
 * @low: Starting index of the merge
 * @size: Size of the merge
 * @direction: Direction of the merge (UP or DOWN)
 */
void bitonic_merge(int *arr, size_t low, size_t size, int direction)
{
	size_t y;
    if (size > 1)
    {
        size_t middle = size / 2;
        print_merge("Merging", arr, low, size, direction);

        for (y = low; y < low + middle; ++y)
        {
            if ((arr[y] > arr[y + middle] && direction == 1) || (arr[y] < arr[y + middle] && direction == 0))
            {
                
                exchange(arr, y, y + middle);
            }
        }

        bitonic_merge(arr, low, middle, direction);
        bitonic_merge(arr, low + middle, middle, direction);
    }
}

/**
 * bitonic_sort_recursive - Recursively performs Bitonic sort on an array
 * @arr: The array to  sort
 * @low: Starting index of the array or subarray
 * @size: Size of the array or subarray
 * @direction: Direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *arr, size_t lower, size_t size, int direction)
{
    if (size > 1)
    {
        size_t middle = size / 2;

        
        bitonic_sort_recursive(arr, lower, middle, 1);

        
        bitonic_sort_recursive(arr, lower + middle, middle, 0);

        
        bitonic_merge(arr, lower, size, direction);
    }
}

/**
 * bitonic_sort - Sorts an array using the Bitonic sort algorithm
 * @arr: The array to sort
 * @size: Size of the array (should be a power of 2)
 */
void bitonic_sort(int *arr, size_t size)
{
    bitonic_sort_recursive(arr, 0, size, 1);
}
