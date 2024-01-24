#include "sort.h"

/**
 * Hoare - chooses the pivot
 *
 * @array: the array
 * @right: the most right of the array
 * @left: the most left of the array
 * @size: the size of the array
 *
 * Return: the pivot
 */
int Hoare(int *array, size_t left, size_t right, size_t size)
{
	int pivot = array[right], temp;
	size_t i = left - 1, j = right + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
		{
			return (i);
		}

		else
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
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
		s = Hoare(array, left, right, size);

		quickSort(array, left, s - 1, size);
		quickSort(array, s, right, size);
	}
}

/**
 * quick_sort_hoare - sorts an array according to quick sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}
