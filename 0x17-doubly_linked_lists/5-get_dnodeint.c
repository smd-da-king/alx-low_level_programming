#include "lists.h"

/**
 * get_dnodeint_at_index - get node at index of a doubly lniked list
 * @head: head of the linked list
 * @index: index to get
 * Return: length of the list
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	size_t count = 0;

	while (head != NULL)
	{
		if (count == index)
			break;
		head = head->next;
		count++;
	}
	return (head);
}
