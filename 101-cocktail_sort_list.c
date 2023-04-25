#include "sort.h"

/**
 * swap_nodes - swap two nodes
 * @a: pointer to first node
 * @b: pointer to second node
 */

void swap_nodes(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	a->next = a;
}

/**
 * reverse_sort - sorts from the tailend
 * @head: head of list
 * @tail: tail of list
 * Return: new head
 */

listint_t *reverse_sort(listint_t *head, listint_t *tail, listint_t *list)
{
	while (tail && tail->prev)
	{
		if (tail->n < tail->prev->n)
		{
			swap_nodes(tail->prev, tail);
			if (tail->prev == NULL)
				list = tail;
			print_list(list);
		}
		else
			tail = tail->prev;
		if (tail->prev == NULL)
			head = tail;
	}
	return (head);
}

/**
 * cocktail_sort_list - sort doubly linked list, cocktail shaker sort
 * @list: pointer to list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *head, *ptr;
	int i, j = 0, swapp = 1;

	if (list == NULL)
		return;

	ptr = *list;
	for (i = 0; ptr; i++)
		ptr = ptr->next;

	if (i < 2)
		return;

	head = *list;
	while (j < i)
	{
		swapp = 0;
		while (head && head->next)
		{
			if (head->n > head->next->n)
			{
				swap_nodes(head, head->next);
				swapp++;
				if (head->prev->prev == NULL)
					*list = head->prev;
				print_list(*list);
			}
			else
				head = head->next;
			if (head->next == NULL)
				tail = head;
		}
		head = reverse_sort(head, tail, *list);
		*list = head;
		j++;
	}
}
