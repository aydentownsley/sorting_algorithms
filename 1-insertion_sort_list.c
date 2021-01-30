#include "sort.h"

/**
 *
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *nnod = NULL, *curr = NULL, *dll = *list, *pnod = NULL;

	while (dll != NULL)
	{
		if (dll->n > dll->next->n)
		{
			curr = dll;
			nnod = dll->next;
			if (nnod->next == NULL)
				curr->next = NULL;
			else
				curr->next = nnod->next;
			if (curr->prev == NULL)
			{
				nnod->prev = NULL;
				*list = nnod;
			}
			else
				curr->prev->next = nnod;
			nnod->next = curr;
			nnod->prev = curr->prev;
			curr->prev = nnod;
			curr->next->prev = curr;
			print_list(*list);
			while (nnod->n < nnod->prev->n)
			{
				pnod = nnod->prev;
				curr = nnod;
				if (pnod->prev == NULL)
				{
					curr->prev = NULL;
					*list = curr;
				}
				else
				{
					curr->prev = pnod->prev;
					pnod->prev->next = nnod;
				}
				pnod->next = curr->next;
				curr->next = pnod;
				curr->next->prev = pnod;
				pnod->prev = curr;
				print_list(*list);
				nnod = nnod->prev;
			}
		}
		dll = dll->next;

	}
}
