#include "binary_trees.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * depth - Calculates the depth of a node
 * @tree: Pointer to the node
 * Return: Depth
 */
int depth(const binary_tree_t *tree)
{
	int d = 0;

	while (tree && tree->parent)
	{
		tree = tree->parent;
		d++;
	}

	return (d);
}

/**
 * is_perfect - Recursive checker if tree is perfect
 * @tree: Pointer to the current node
 * @depth_leaf: Expect depth for leaves
 * @level: Current level of node
 * Return: 1 if perfect, 0 if not
 */
int is_perfect(const binary_tree_t *tree, int depth_leaf, int level)
{
	if (!tree)
		return (1);

	if (!tree->left && !tree->right)
		return (depth_leaf == level);

	if (!tree->left || !tree->right)
		return (0);

	return (is_perfect(tree->left, depth_leaf, level + 1) &&
			is_perfect(tree->right, depth_leaf, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to root node
 * Return: 1 if perfect, 0 if otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d;

	if (!tree)
		return (0);

	d = depth(tree);

	return (is_perfect(tree, d, 0));
}
