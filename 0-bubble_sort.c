#include "sort.h"



void bubble_sort(int *array, size_t size)
{
	size_t pass;
	size_t index;
	int temp;
	int swap;

	if (array == NULL || size < 2)
		return;
	for (pass = 0; pass < size -1; pass++)
	{
		swap = 0;

		for (index = 0; index < size - pass -1; index++)
		{
			if (array[index] > array[index + 1])
			{
				/*swap the elements */
				temp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = temp;

				swap = 1;
			}

		}
		print_array(array, size);
		if (swap == 0)
			break;
	}
}
