#include "sort.h"

/**
 * counting_sort - sort an array using counting sort
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, max = array[0];
	size_t i, j;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = calloc((max + 1), sizeof(int));
	if (!count)
		return;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 0, j = 0; (int)i < max + 1; i++)
	{
		j += count[i];
		count[i] = j;
	}
	print_array(count, max + 1);

	output = malloc(size * sizeof(int));
	if (!output)
		return;

	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
