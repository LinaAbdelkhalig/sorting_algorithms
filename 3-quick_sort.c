#include "sort.h"

/**
 * Lomuto - chooses the pivot
 *
 * @array: the array
 * @right: the most right of the array
 * @left: the most left of the array
 * @size: the size of the array
 *
 * Return: the pivot
 */
int Lomuto(int *array, size_t left, size_t right, size_t size)
{
	int pivot = array[right], temp;
	size_t i, j = left;

	for (i = left; i < right; i++)
	{
		if (array[i] <= pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);

			j++;
		}
	}

	temp = array[j];
	array[j] = array[right];
	array[right] = temp;
	if (right != j)
		print_array(array, size);

	return (j);
}

/**
 * quickSort - sorts an array according to quick sort algorithm
 *
 * @array: the array to be sorted
 * @right: the most right of the array
 * @left: the most left of the array
 * @size: the size of the array
 */
void quickSort(int *array, size_t left, size_t right, size_t size)
{
	size_t s;

	if (left < right)
	{
		s = Lomuto(array, left, right, size);

		if (s != 0)
			quickSort(array, left, s - 1, size);
		if (s + 1 < size)
			quickSort(array, s + 1, right, size);
	}
}

/**
 * quick_sort - sorts an array according to quick sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array)
		return;
	quickSort(array, 0, size - 1, size);
}
