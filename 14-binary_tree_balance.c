#include "binary_trees.h"
#include <stddef.h>

/**
 * height - Helper function to calculate the height of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Height of the tree
 */
static int height(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);
	left = height(tree->left);
	right = height(tree->right);

	return ((left > right ? left : right) + 1);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Balance factor, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (height(tree->left) - height(tree->right));
}
