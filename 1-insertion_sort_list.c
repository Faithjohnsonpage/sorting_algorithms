#include "sort.h"

void insertion_sort_list(listint_t **list);

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the insertion sort algorithm.
 *
 * @list: A pointer to the head of the doubly linked list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;
	int count = 0, i, j, temp_i, current_j;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	while (current != NULL)
	{
		count += 1;
		current = current->next;
	}

	if (count < 2)
		return;

	for (i = 1; i < count; i++)
	{
		j = i - 1;
		temp = *list;
		temp_i = i;
		while (temp_i)
		{
			temp = temp->next;
			temp_i--;
		}

		current = *list;
		current_j = j;
		while (current_j)
		{
			current = current->next;
			current_j--;
		}

		while (current != NULL && temp != NULL && current->n > temp->n)
		{
			temp->prev = current->prev;
			current->next = temp->next;
			temp->next = current;
			if (current->next != NULL)
				current->next->prev = current;
			current->prev = temp;
			if (temp->prev != NULL)
				temp->prev->next = temp;
			current = temp->prev;
			if (current == NULL)
				*list = temp;

			print_list(*list);
		}
	}
}
