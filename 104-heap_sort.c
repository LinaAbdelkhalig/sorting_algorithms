#include "sort.h"

/**
 * sift_down - repair the heap whose root element is at start
 *
 * @array: the heap to be repaired
 * @start: the start of the array
 * @end: the end of the array
 * @size: the size of the array
 */
void sift_down(int *array, int start, int end, size_t size)
{
	int root = start, child, temp;

	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		if (child + 1 <= end && array[child] < array[child + 1])
			child++;

		if (array[root] < array[child])
		{
			temp = array[root];
			array[root] = array[child];
			array[child] = temp;
			print_array(array, size);

			root = child;
		}
		else
			return;
	}
}

/**
 * heapify - heapify the binary tree
 *
 * @array: the binary tree
 * @size: the size of the tree
 */
void heapify(int *array, size_t size)
{
	int start;

	for (start = (size - 2) / 2; start >= 0; start--)
	{
		sift_down(array, start, size - 1, size);
	}
}

/**
 * heap_sort - sorts an array according to the heap sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array to be sorted
 */
void heap_sort(int *array, size_t size)
{
	int end, temp;

	if (!array || size < 2)
		return;

	heapify(array, size);

	for (end = size - 1; end > 0; end--)
	{
		temp = array[end];
		array[end] = array[0];
		array[0] = temp;
		print_array(array, size);

		sift_down(array, 0, end - 1, size);
	}
}
