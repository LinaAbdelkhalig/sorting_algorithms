#include "sort.h"

/**
 * swap - swaps two nodes of the list
 *
 * @list: the list to be sorted
 * @n: the node to be swapped
 */
void swap(listint_t **list, listint_t *n)
{
	listint_t *temp = n->next;

	if (n->prev)
		n->prev->next = temp;
	else
		*list = temp;

	temp->prev = n->prev;

	if (temp->next)
		temp->next->prev = n;

	n->next = temp->next;
	n->prev = temp;
	temp->next = n;

	print_list(*list);
}

/**
 * cocktail_sort_list - sorts a doubly linked list according to cocktail shaker
 *
 * @list: the list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *temp;

	if (!list || !(*list) || !(*list)->next)
		return;

	while (swapped)
	{
		swapped = 0;
		for (temp = *list; temp && temp->next; temp = temp->next)
		{
			if (temp->n > temp->next->n)
			{
				swap(list, temp);
				temp = temp->prev;
				swapped = 1;
			}
		}

		if (!swapped)
			break;

		swapped = 0;

		for (; temp && temp->prev; temp = temp->prev)
		{
			if (temp->prev->n > temp->n)
			{
				swap(list, temp->prev);
				temp = temp->next;
				swapped = 1;
			}
		}
	}
}
