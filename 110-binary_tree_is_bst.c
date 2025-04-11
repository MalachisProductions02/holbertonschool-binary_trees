#include "binary_trees.h"
#include <stdlib.h>
#include <limits.h>

/**
 * is_bst_helper - Helper to validate BST by checking node
 * values in range
 * @node: Pointer to the current node
 * @min: Minimum allowed value for the current node
 * @max: Maximum allowed value for the current node
 * Return: 1 if subtreeis valid BST, 0 otherwise
 */
int is_bst_helper(const binary_tree_t *node, int min, int max)
{
	if (!node)
		return (1);

	if (node->n <= min || node->n >= max)
		return (0);
	return (is_bst_helper(node->left, min, node->n) &&
			is_bsthelper(node->right, node->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if valid BST, 0 otherwise
 */
int binary_tree_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_bst_helper(tree, INT_MIN, INT_MAX));
