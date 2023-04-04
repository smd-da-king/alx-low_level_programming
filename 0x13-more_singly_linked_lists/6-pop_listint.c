#include "lists.h"

/**
 * pop_listint - Entry point
 * Description: Deletes the head node of a listint_t linked list,
 * and returns the head node’s data (n).
 * @head: Pointer to pointer of first node in linked list
 *
 * Return: 0, if the linked list is empty
 */

int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int info;

	/* Checks if head is empty */
	if (!*head)
	{
		return (0);
	}
	/* Stores head node in temp */
	tmp = *head;

	/* Info stored in the head node */
	info = tmp->n;

	/* Makes next node the new head node */
	*head = (*head)->next;

	free(tmp);

	return (info);
}
