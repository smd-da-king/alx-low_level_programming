#include "lists.h"

/**
 * free_listint2 - Entry point
 * Description: Frees a listint_t list and sets the head to NULL
 * @head: Pointer to pointer of the head node of the linked list
 */

void free_listint2(listint_t **head)
{
	listint_t *tmp;

	/* Checks if head is NULL or empty */
	if (!head)
	{
		return;
	}
	while (*head)
	{
		/* Sets new to next node */
		tmp = (*head)->next;
		free(*head);

		/* Moves to new node */
		*head = tmp;
	}
	head = NULL;
}

