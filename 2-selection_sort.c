#include "sort.h"

/**
 * switcharoo - switch two elements of the array
 * @x: the first eleement
 * @y: the second element
 * Return: void
 */

void switcharoo(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * selection_sort - sorts an array using selection sort
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min;

	if (!array || size == 0 || size == 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = (i + 1); j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (i != min)
		{
			switcharoo(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}
