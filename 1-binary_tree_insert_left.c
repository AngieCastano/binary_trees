#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as a left-child of another node
 * @parent: A pointer to the parent node
 * @value: Value to store in new node
 * Return: Pointer to the new node, NULL upon failure
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *copy_left;

	if (!parent)
		return (NULL);

	if (!value)
		return (NULL);

	if (!parent->left)
		return (parent->left = binary_tree_node(parent, value));

	if (parent->left)
	{
		copy_left = parent->left;
		parent->left = binary_tree_node(parent, value);
		parent->left->left = copy_left;
		copy_left->parent = parent->left;
	}

	return (parent->left);
}
