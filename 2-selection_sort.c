#include "sort.h"

/**
 * selection_sort - sorts an array using the selction sort algorithm
 * and prints the sorted array
 * @array: the array to sort
 * @size: the size of the array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t  min, temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}

		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
