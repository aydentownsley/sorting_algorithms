#include "sort.h"

/**
 * insertion_sort_list - function to insertion sort a list
 * @list: list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *dll = (*list)->next, *pnod;

	if (list == NULL || (*list)->next == NULL)
		return;

	while (dll)
	{
		curr = dll;
		pnod = dll->prev;
		while (pnod && curr->n < pnod->n)
		{
			if (pnod->prev != NULL)
				pnod->prev->next = curr;
			if (curr->next != NULL)
				curr->next->prev = pnod;
			if (pnod->prev == NULL)
				(*list) = curr;
			pnod->next = curr->next;
			curr->next = pnod;
			curr->prev = pnod->prev;
			pnod->prev = curr;
			print_list(*list);
			pnod = curr->prev;
		}
		dll = dll->next;
	}
}
