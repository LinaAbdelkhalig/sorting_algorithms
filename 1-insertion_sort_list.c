#include "sort.h"

/**
 * insertion_sort_list - sorts a dll using insetion sort
 * @list: the list ro be sorted
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp;

	if (!list || !*list)
		return;

	curr = (*list)->next;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		while (temp && temp->prev && temp->n < temp->prev->n)
		{
			temp->prev->next = temp->next;
			if (temp->next)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;
			if (!temp->prev)
				*list = temp;
			else
				temp->prev->next = temp;
			print_list((const listint_t *)*list);
		}
	}
}
