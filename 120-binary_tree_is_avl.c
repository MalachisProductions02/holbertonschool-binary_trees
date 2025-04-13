#include "binary_trees.h"

/**
 * height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure.
 * Return: Height or 0 if tree is NULL.
 */
int height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + ((height(tree->left) > height(tree->right)) ?
		height(tree->left) : height(tree->right)));
}

/**
 * is_bst - Checks if a binary tree is a valid BST.
 * @tree: Pointer to the root node.
 * @min: Minimum allowed value.
 * @max: Maximum allowed value.
 * Return: 1 if valid BST, 0 otherwise.
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (is_bst(tree->left, min, tree->n) &&
		is_bst(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node.
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_h, right_h;

	if (!tree)
		return (0);

	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	left_h = height(tree->left);
	right_h = height(tree->right);

	if (abs(left_h - right_h) > 1)
		return (0);

	if ((tree->left && !binary_tree_is_avl(tree->left)) ||
	    (tree->right && !binary_tree_is_avl(tree->right)))
		return (0);

	return (1);
}
