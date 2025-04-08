#include "binary_trees.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * binary_tree_is_root - Checks if a node is a root
 * @node: Pointer to the node to check
 * Return: 1 if node is a root, 0 otherwise.
 */
int binary_tree:is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->parent == NULL)
		return (1);

	return (0);
}

