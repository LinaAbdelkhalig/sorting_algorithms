#include "sort.h"

/**
 * merge - merges the two sorted arrays into one array
 *
 * @b: the first part
 * @c: the second part
 * @s_b: the size of b
 * @s_c: the size of c
 * @array: the large array
 */
void merge(int *b, int *c, int *array, size_t s_b, size_t s_c)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(b, s_b);
	printf("[right]: ");
	print_array(c, s_c);

	while (i < s_b && j < s_c)
	{
		if (b[i] <= c[j])
			array[k++] = b[i++];
		else
			array[k++] = c[j++];
	}

	while (i < s_b)
		array[k++] = b[i++];

	while (j < s_c)
		array[k++] = c[j++];

	printf("[Done]: ");
	print_array(array, s_b + s_c);
}

/**
 * merge_sort - sorts an array according to merge sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *b, *c;
	size_t i, middle = size / 2;

	if (!array)
		return;

	b = malloc(sizeof(int) * middle);
	if (!b)
		return;

	c = malloc(sizeof(int) * (size - middle));
	if (!c)
	{
		free(b);
		return;
	}

	if (size > 1)
	{
		for (i = 0; i < middle; i++)
			b[i] = array[i];
		for (i = middle; i < size; i++)
			c[i - middle] = array[i];

		merge_sort(b, middle);
		merge_sort(c, size - middle);
		merge(b, c, array, middle, size - middle);
	}

	free(b);
	free(c);
}
