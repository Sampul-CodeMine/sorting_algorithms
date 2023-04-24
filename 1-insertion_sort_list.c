#include "sort.h"

void swap(listint_t **, listint_t **);

/**
 * insertion_sort_list - function to sort a double linked list using
 * the Insertion sort algorithm
 * @list: The double linked-list to sort
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *key;
	listint_t *back;

	if (list == NULL)
		return;

	key = *list;
	while (key && key->next != NULL)
	{
		while (key->next != NULL)
		{
			if (key->n > key->next->n)
			{
				back = key;
				if (key->prev != NULL)
					key->prev->next = back->next;
				key->next->prev = back->prev;
				key->prev = back->next;
				key->next = back->next->next;
				key->prev->next = back;

				if (key->next != NULL)
					key->next->prev = back;
				if (key->prev->prev == NULL)
					*list = key->prev;
				print_list(*list);
				key = *list; 
			}
			key = key->next;
		}
		key = key->next;
	}
}
