#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 *  in ascending order using the Insertion sort algorithm
 *  @list: list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *cnode, *temp;

	if (list == NULL)
	{
		return;
	}

	for (cnode = *list; cnode != NULL; cnode = cnode->next)
	{

		while (cnode->next && (cnode->next->n < cnode->n))
		{
			temp = cnode->next;
			cnode->next = temp->next;
			temp->prev = cnode->prev;

			if (cnode->prev)
				cnode->prev->next = temp;

			if (temp->next)
			{
				temp->next->prev = cnode;
			}
			cnode->prev = temp;
			temp->next = cnode;

			if (temp->prev)
				cnode = temp->prev;


			else
				*list = temp;

			print_list(*list);
		}
	}
}
