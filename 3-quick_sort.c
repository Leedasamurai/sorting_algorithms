#include "sort.h"

/**
 * quick_sort - Sorts an array in ascending order
 * @array: Pointer to an array.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursive function.
 *
 * @array: Pointer to an array.
 * @low: Index of the low element.
 * @high: Index of the high element.
 * @size: Size of the array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int partition_index;

	if (low < high)
	{
		partition_index = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, partition_index - 1, size);
		quick_sort_recursive(array, partition_index + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort.
 *
 * @array: Pointer to an array.
 * @low: Index of the low element.
 * @high: Index of the high element.
 * @size: Size of the array.
 *
 * Return: Partition index.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	print_array(array, size);

	return (i + 1);
}
