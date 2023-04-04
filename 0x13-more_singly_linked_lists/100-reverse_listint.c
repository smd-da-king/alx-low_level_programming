#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t list.
 * @head: A pointer to the address of
 *        the head of the list_t list.
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *ahead1, *behind1;

	if (head == NULL || *head == NULL)
		return (NULL);

	behind1 = NULL;

	while ((*head)->next != NULL)
	{
		ahead1 = (*head)->next;
		(*head)->next = behind1;
		behind1 = *head;
		*head = ahead1;
	}

	(*head)->next = behind1;

	return (*head);
}
