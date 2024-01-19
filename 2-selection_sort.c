#include "sort.h"

/**
 * selection_sort - sorts an array using selection sort
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	unsigned int i, j;
	int min, temp;
	if (!array || size == 0 || size == 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		temp = array[min];
		array[min] = array[i];
		array[i] = temp;
		print_array(array, size);
	}
}
