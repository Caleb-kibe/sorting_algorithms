#include "sort.h"

/**
 * swap - swaps two elements
 * @a: first element
 * @b: second element
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition_array - divides the array into two after finding
 * the pivot element.
 * @a: the array to partition
 * @lb: lower bound of the array
 * @ub: upper bound of the array
 * @size: the size of the array
 *
 * Return: the pivot point from where the array will be divided
 */
int partition_array(int a[], int lb, int ub, size_t size)
{
	int pivot = a[lb + 1];
	int start = lb;
	int end = ub;

	while (start < end)
	{
		while (a[start] <= pivot)
		{
			start++;
		}
		while (a[end] > pivot)
		{
			end--;
		}
		if (start < end)
		{
			swap(&a[start], &a[end]);
		}
	}
	swap(&a[lb], &a[end]);
	print_array(a, size);
	return (end);
}

/**
 * quick_sort_recursive - sorts an array using quick sort algorithm
 * by calling itself recursively
 * @a: array to sort
 * @lb: lower bound of the array
 * @ub: upper bound of the array
 * @size: size of the array
 */
void quick_sort_recursive(int a[], int lb, int ub, size_t size)
{
	int mid;

	if (lb < ub)
	{
		mid = partition_array(a, lb, ub, size);
		quick_sort_recursive(a, lb, (mid - 1), size);
		quick_sort_recursive(a, (mid + 1), ub, size);
	}
}
/**
 * quick_sort - sorts an array using the quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
