#include "binary_trees.h"

/**
 * rebalance - Rebalances an AVL tree after insertion.
 * @tree: Double pointer to the root of the tree.
 * @node: The newly inserted node.
 *
 * Return: Pointer to the new root of the tree.
 */
avl_t *rebalance(avl_t **tree, avl_t *node)
{
	int balance;

	if (!tree || !*tree || !node)
		return (NULL);

	while (node)
	{
		balance = binary_tree_balance(node);

		if (balance > 1)
		{
			if (binary_tree_balance(node->left) < 0)
				node->left = binary_tree_rotate_left(node->left);
			node = binary_tree_rotate_right(node);
		}
		else if (balance < -1)
		{
			if (binary_tree_balance(node->right) > 0)
				node->right = binary_tree_rotate_right(node->right);
			node = binary_tree_rotate_left(node);
		}

		if (node->parent == NULL)
			*tree = node;

		node = node->parent;
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: Double pointer to the root of the tree.
 * @value: Value to insert.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *current, *new_node;

	if (!tree)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	current = *tree;
	while (1)
	{
		if (value == current->n)
			return (NULL); /* No se permiten duplicados */

		if (value < current->n)
		{
			if (current->left == NULL)
			{
				new_node = binary_tree_node(current, value);
				current->left = new_node;
				break;
			}
			current = current->left;
		}
		else
		{
			if (current->right == NULL)
			{
				new_node = binary_tree_node(current, value);
				current->right = new_node;
				break;
			}
			current = current->right;
		}
	}

	return (rebalance(tree, new_node));
}
