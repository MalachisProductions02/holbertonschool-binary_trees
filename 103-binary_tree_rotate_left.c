#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_rotate_left - Rotates a binary tree to the left
 * @tree: Pointer to the root node of the tree to rotate
 * Return: Pointer to the new root node of the tree after rotation
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (!tree || !tree->right)
		return (tree);

	new_root = tree->right;
	tree->right = new_root->left;
	if (new_root->left)
		new_root->left->parent = tree;

	new_root->left = tree;
	tree->parent = new_root;

	return (new_root);
}
