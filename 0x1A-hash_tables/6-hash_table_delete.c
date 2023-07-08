#include "hash_tables.h"

/**
 * hash_table_delete - free the hash table
 * @ht: hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *tmp;

	for (i = 0; i < ht->size; i++)
	{
		tmp = ht->array[i];
		while (tmp != NULL)
		{
			ht->array[i] = tmp->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
			tmp = ht->array[i];
		}
	}
	free(ht->array);
	free(ht);
}
