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
	listint_t *key = *list;
	listint_t *back;
	listint_t *aux;

	if (!key || (!key->prev && !key->next))
		return;

	while (key && key->next)
	{
		if (key->n > key->next->n)
		{
			aux = key;
			swap(&aux, list);
			print_list(*list);
			key = aux;
			back = aux;
			while (back && back->prev)
			{
				if (back->n < back->prev->n)
				{
					aux = back->prev;
					swap(&aux, list);
					print_list(*list);
					back = aux->next;
				}
				back = back->prev;
			}
		}
		key = key->next;
	}
}

/**
 * swap - function that swaps two (2) nodes of a DLL (Double Linked-List)
 * @key_ele: the key node to change
 * @list: the DLL head
 * Return: Nothing
*/
void swap(listint_t **key_ele, listint_t **list)
{
	listint_t *holder = *key_ele;
	listint_t *temp, *pack;

	if (!(*key_ele)->prev)
		*list = (*key_ele)->next;

	holder = pack = *key_ele;
	temp = holder->next;

	holder->next = temp->next;
	pack = holder->prev;
	holder->prev = temp;
	temp->next = holder;
	temp->prev = pack;

	if (temp->prev)
		temp->prev->next = temp;

	if (holder->next)
		holder->next->prev = holder;

	*key_ele = temp;
}
