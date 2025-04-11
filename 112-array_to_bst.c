#include "binary_trees.h"

/**
 * array_to_bst - Biulds a BST from an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *root = NULL;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);

	return (root);
}
