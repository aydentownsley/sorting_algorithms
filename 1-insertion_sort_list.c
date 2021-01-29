#include "sort.h"

/**
 *
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *next = *list, *curr = *list, *dll = *list;

	while (dll->next != NULL)
	{
		next = dll->next;
		curr = dll;
		if (curr->n > next->n)
		{
			curr->next = next->next;
			curr->prev->next = next;
			next->next = curr;
			next->prev = curr->prev;
			curr->prev = next;
			curr->next->prev = curr;
			print_list(*list);
			if (dll->prev->n > next->n)
				insertion_sort_list(list);
		}
		dll = dll->next;
	}
}
