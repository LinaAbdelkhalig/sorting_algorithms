#include "sort.h"

/**
 * shell_sort - sorts an array according to shell sort using Knuth sequence
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t gap, i, j;

	if (!array || size < 2)
		return;

	gap = 1;

	/* the Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap)
	{
		for (i = gap; i < size; i += 1)
		{
			temp = array[i];
			for (j = i; (j >= gap) && (array[j - gap] > temp); j -= gap)
				array[j] = array[j - gap];

			array[j] = temp;
		}
		gap /= 3;
		print_array(array, size);
	}
}
