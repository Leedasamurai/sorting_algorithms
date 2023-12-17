#include "sort.h"

/**
 * swap - Swaps two integer values in an array and prints the array.
 * @array: The integer array to sort.
 * @size: The size of the array.
 * @a: Address of the first value.
 * @b: Address of the second value.
 *
 * Return: void.
 */
void swap(int *array, size_t size, int *a, int *b)
{
	if (a != b && a && b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}

/**
 * lomuto_partition - Partitions the array using the Lomuto scheme.
 * @array: The integer array to sort.
 * @size: The size of the array.
 * @lo: The low index of the sort range.
 * @hi: The high index of the sort range.
 *
 * Return: Partition index.
 */
size_t lomuto_partition(int *array, size_t size, size_t lo, size_t hi)
{
	int i;
	size_t j;
	int pivot = array[hi];

	for (i = j = lo; j < hi; j++)
		if (array[j] < pivot)
			swap(array, size, &array[j], &array[i++]);

	swap(array, size, &array[i], &array[hi]);

	return (i);
}


/**
 * quicksort - Recursive quicksort using Lomuto partitioning.
 * @array: The integer array to sort.
 * @size: The size of the array.
 * @lo: The low index of the sort range.
 * @hi: The high index of the sort range.
 *
 * Return: void.
 */
void quicksort(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	if (lo < hi)
	{
		size_t p = lomuto_partition(array, size, lo, hi);

		quicksort(array, size, lo, p - 1);
		quicksort(array, size, p + 1, hi);
	}
}

/**
 * quick_sort - Calls quicksort to perform quicksort on the array.
 * @array: The integer array to sort.
 * @size: The size of the array.
 *
 * Return: void.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, size, 0, size - 1);
}

