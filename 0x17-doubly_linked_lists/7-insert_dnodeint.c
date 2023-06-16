#include "lists.h"

/**
 * insert_dnodeint_at_index - add a node at the index of doubly lniked list
 * @h: head of the linked list
 * @idx: index of the new node
 * @n: data value
 * Return: adress of new element | NULL (failed)
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *newNode, *tmp = *h;
	unsigned int i = 0, len = dlistint_len(*h);

	if (idx == 0)
		return (add_dnodeint(h, n));
	while (tmp != NULL)
	{
		if (i == idx - 1)
			break;
		tmp = tmp->next;
		i++;
	}
	newNode = malloc(sizeof(dlistint_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = n;
	if (idx > len)
	{
		free(newNode);
		return (NULL);
	}
	if (len == idx)
		return (add_dnodeint_end(h, n));

	newNode->prev = tmp;
	tmp->next->prev = newNode;
	newNode->next = tmp->next;
	tmp->next = newNode;
	return (newNode);
}

/**
 * dlistint_len - count the length of doubly lniked list
 * @h: head of the linked list
 * Return: length of the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		h = h->next;
		count++;
	}
	return (count);
}
