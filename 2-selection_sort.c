#include "sort.h"

/**
 * selection_sort - Sorts an array in ascending order.
 *
 * @array: Pointer to an array.
 * @size: Size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, sm_idx;

	if (!array || !size)
		return;

	for (i = 0; i < size - 1; i++)
	{
		sm_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[sm_idx])
				sm_idx = j;
		}

		if (sm_idx != i)
		{
			int temp = array[i];

			array[i] = array[sm_idx];
			array[sm_idx] = temp;
			print_array(array, size);
		}
	}
}

