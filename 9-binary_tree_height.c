#include "binary_trees.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * binary_tree_height - Measures the heaight of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 * Return: Height or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	left_h = binary_tree_height(tree->left);
	right_h- = binary_tree_height(tree->right);

	return ((left_h > right_h ? left_h : right_h) + 1);
}
