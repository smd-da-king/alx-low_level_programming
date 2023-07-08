#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
shash_node_t *create_node(const char *key, const char *value);
void sort_node(shash_table_t *ht, shash_node_t *node);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);


/**
 * shash_table_create - to create a hash table
 * @size: size of the table
 * Return: pointer to the table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table = (shash_table_t *)malloc(sizeof(shash_table_t));
	unsigned long int i;

	if (table == NULL)
	{
		return (NULL);
	}

	table->size = size;
	table->shead = NULL;
	table->stail = NULL;
	table->array = (shash_node_t **)malloc(sizeof(shash_node_t *) * size);
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		table->array[i] = NULL;
	}

	return (table);
}

/**
 * create_node - create a node
 * @key: key of the node
 * @value: data
 * Return: node
 */
shash_node_t *create_node(const char *key, const char *value)
{
	shash_node_t *node;

	node = (shash_node_t *) malloc(sizeof(shash_node_t));
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
	node->snext = NULL;
	node->sprev = NULL;
	return (node);
}

/**
 * shash_table_set - set an element into HT
 * @ht: hash table
 * @key: key of the element
 * @value: value of the element
 * Return: 1 (success) | 0 (failed)
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *node, *tmp;
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
	sort_node(ht, node);
	return (1);
}

/**
 * sort_node - place node in HT in a sorted order
 * @ht: hash table
 * @node: node
 */
void sort_node(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *tmp;

	if (ht->shead == NULL)
	{
		ht->shead = node;
		ht->stail = node;
		return;
	}

	tmp = ht->shead;
	while (tmp)
	{
		if (strcmp(tmp->key, node->key) > 0)
		{
			node->snext = tmp;
			node->sprev = tmp->sprev;
			tmp->sprev = node;
			if (node->sprev == NULL)
				ht->shead = node;
			else
				node->sprev->snext = node;
			return;
		}
		tmp = tmp->snext;
	}
	node->sprev = ht->stail;
	ht->stail->next = node;
	ht->stail = node;
}

/**
 * shash_table_get - get the value associated with the key
 * @ht: hash table
 * @key: key of the element
 * Return: value (success) | NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *tmp;

	if (ht == NULL || ht->size == 0 || key == NULL)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}

	return (NULL);
}

/**
 * shash_table_print - print the hash table
 * @ht: hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	int flag = 0;
	shash_node_t *tmp;

	if (ht == NULL || ht->array == NULL)
		return;

	printf("{");

	tmp = ht->shead;
	while (tmp)
	{
		if (flag)
			printf(", ");

		flag = 1;
		printf("'%s': ", tmp->key);
		printf("'%s'", tmp->value);
		tmp = tmp->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - print the hash table in reverse
 * @ht: hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	int flag = 0;
	shash_node_t *tmp;

	if (ht == NULL || ht->array == NULL || ht->shead == NULL)
		return;

	printf("{");

	tmp = ht->stail;
	while (tmp)
	{
		if (flag)
			printf(", ");

		flag = 1;
		printf("'%s': ", tmp->key);
		printf("'%s'", tmp->value);
		tmp = tmp->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - free HT
 * @ht: hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *tmp;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;

	tmp = ht->stail;
	while (tmp != NULL)
	{
		ht->stail = tmp->sprev;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
		tmp = ht->stail;
	}

	ht->shead = NULL;
	ht->stail = NULL;
	ht->size = 0;
	free(ht->array);
	ht->array = NULL;
	free(ht);
}
