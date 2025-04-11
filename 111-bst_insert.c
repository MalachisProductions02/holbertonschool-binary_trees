#include "binary_trees.h"

/**
 * bst_insert_recursive - Recursive helper to insert a value
 * @parent: Pointer to the parent node
 * @current: Pointer to the current node
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert_recursive(bst_t *parent, bst_t *current, int value)
{
	if (current == NULL)
		return (binary_tree_node(parent, value));

	if (value < current->n)
	{
		if (current->left == NULL)
			return (current->left = binary_tree_node(current, value));
		return (bst_insert_recursive(current, current->left, value));
	}
	else if (value > current->n)
	{
		if (current->right == NULL)
			return (current->right = binary_tree_node(current, value));
		return (bst_insert_recursive(current, current->right, value));
	}

	return (NULL);
}

/**
 * bst_insert - Inserts a value into a Binary Search Tree
 * @tree: Double pointer to the root node of the BST
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	return (bst_insert_recursive(NULL, *tree, value));
}
