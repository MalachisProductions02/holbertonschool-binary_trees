#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_is_leaf - Checks if a node is a leaf
 * @node: Pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0. Returns 0 if node is NULL
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);

	if (node->left == NULL && node->right == NULL)
		return (NULL);

	return (0);
}
