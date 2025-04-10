#include "binary_trees.h"
#include <stdlib.h>

/**
 * queue_push - Adds a node to the end of the queue
 * @queue: Pointer to the array of node pointers
 * @node: Node to add
 * @size: Pointer to the current size of the queue
 * @capacity: Pointer to the capacity of the queue
 */
void queue_push(binary_tree_t ***queue, binary_tree_t *node, size_t *size, size_t *capacity)
{
	if (*size >= *capacity)
	{
		*capacity += 10;
		*queue = realloc(*queue, *capacity * sizeof(binary_tree_t *));
		if (!*queue)
			return;
	}
	(*queue)[*size] = node;
	(*size)++;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue = NULL;
	size_t size = 0, capacity = 0, i = 0;
	int seen_null = 0;

	if (!tree)
		return (0);

	queue = malloc(10 * sizeof(binary_tree_t *));
	if (!queue)
		return (0);
	capacity = 10;

	queue_push(&queue, (binary_tree_t *)tree, &size, &capacity);

	while (i < size)
	{
		binary_tree_t *node = queue[i++];

		if (!node)
		{
			seen_null = 1;
		}
		else
		{
			if (seen_null)
			{
				free(queue);
				return (0);
			}
			queue_push(&queue, node->left, &size, &capacity);
			queue_push(&queue, node->right, &size, &capacity);
		}
	}

	free(queue);
	return (1);
}
