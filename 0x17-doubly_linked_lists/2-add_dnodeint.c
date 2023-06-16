#include "lists.h"

/**
 * add_dnodeint - add a node at the beginning of doubly lniked list
 * @head: head of the linked list
 * @n: data value
 * Return: adress of new element | NULL (failed)
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *newNode;

	newNode = malloc(sizeof(dlistint_t));
	if (newNode != NULL)
	{
		newNode->n = n;
		newNode->next = NULL;
		newNode->prev = NULL;
		if (*head != NULL)
		{
			newNode->next = *head;
			(*head)->prev = newNode;
		}
		*head = newNode;
		return (newNode);
	}
	return (NULL);
}
