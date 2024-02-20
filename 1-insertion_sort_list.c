#include "sort.h"

/**
 * insertion_sort_list - sorts a double linked list
 * using the insertion algorithm
 * @list: the double linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *temp, *insert;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = iter->next)
	{
		temp = iter;
		insert = iter->prev;

		while (insert != NULL && insert->n > temp->n)
		{
			insert->next = insert;
			insert = iter->prev;
			insert->next = temp;
		}
	}
	print_list(*list);
}
