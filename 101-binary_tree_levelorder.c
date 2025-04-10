#include "binary_trees.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * struct queue_node_s - Simple queue structure for tree nodes
 * @node: Pointer to a binary tree node
 * @next: Pointer to the next node in the queue
 */
typedef struct queue_node_s
{
	const binary_tree_t *node;
	struct queue_node_s *next;
} queue_node_t;

/**
 * enqueue - Adds a tree node to the end of the queue
 * @head: Pointer to the head of the queue
 * @tail: Pointer to the tail of the queue
 * @node: Binary tree node to add
 */
void enqueue(queue_node_t **head, queue_node_t **tail, const binary_tree_t *node)
{
	queue_node_t *new = malloc(sizeof(queue_node_t));

	if (!new)
		return;
	new->node = node;
	new->next = NULL;

	if (*tail)
		(*tail)->next = new;
	else
		*head = new;

	*tail = new;
}

/**
 * dequeue - Removes and returns a node from  of the queue
 * @head: Pointer to the head of the queue
 * Return: Pointer to the binary tree node
 */
const binary_tree_t *dequeue(queue_node_t **head)
{
	queue_node_t *tmp;
	const binary_tree_t *node;

	if (!head || !*head)
		return (NULL);

	tmp = *head;
	*head = (*head)->next;
	node = tmp->node;
	free(tmp);

	return (node);
}

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree
 * @func: Function to call for each node's value
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_node_t *head = NULL, *tail = NULL;
	const binary_tree_t *current;

	if (!tree || !func)
		return;

	enqueue(&head, $&tail, tree);

	while (head)
	{
		current = dequeue(&head);
		func(current->n);

		if (current->left)
			enqueue(&head, &tail, current->left);
		if (current->right)
			enqueue(&head, &tail, current->right);
	}
}
