#include "binary_trees.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Pointer to the lowest common ancestor, or NULL if no common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *p1 = first;

	if (first == NULL || second == NULL)
		return (NULL);

	while (p1)
	{
		const binary_tree_t *temp = second;

		while (temp)
		{
			if (p1 == temp)
				return ((binary_tree_t *)p1);
			temp = temp->parent;
		}
		p1 = p1->parent;
	}
	return (NULL);
}
