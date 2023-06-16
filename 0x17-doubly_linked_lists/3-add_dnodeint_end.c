#include "lists.h"

/**
 * add_dnodeint_end - add a node at the end of doubly lniked list
 * @head: head of the linked list
 * @n: data value
 * Return: adress of new element | NULL (failed)
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *newNode, *tmp = *head;

	newNode = malloc(sizeof(dlistint_t));
	if (newNode != NULL)
	{
		newNode->n = n;
		newNode->next = NULL;
		newNode->prev = NULL;
		if (tmp != NULL)
		{
			while (tmp)
			{
				if ((tmp)->next == NULL)
					break;
				tmp = (tmp)->next;
			}
			(tmp)->next = newNode;
			newNode->prev = tmp;
		}
		else
			*head = newNode;
		return (newNode);
	}
	return (NULL);
}
