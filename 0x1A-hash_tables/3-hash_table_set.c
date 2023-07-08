#include "hash_tables.h"

hash_node_t *create_node(const char *key, const char *value);

/**
 * hash_table_set - set an element in th hash table
 * @ht: hash table
 * @key: key of the element
 * @value: value of the element
 * Return: 1 (success) | 0 (failed)
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node, *tmp;
	unsigned long int idx;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || value == NULL)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[idx];

	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(ht->array[idx]->value);
			ht->array[idx]->value = strdup(value);
			if (ht->array[idx]->value == NULL)
				return (0);
			return (1);
		}
		tmp = tmp->next;
	}

	node = create_node(key, value);
	if (node == NULL)
		return (0);
	node->next = ht->array[idx];
	ht->array[idx] = node;
	return (1);

}

/**
 * create_node - create a node
 * @key: key of the node
 * @value: data
 * Return: node
 */
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *node;

	node = (hash_node_t *) malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (NULL);

	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (NULL);
	}

	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (NULL);
	}

	node->next = NULL;
	return (node);
}
