#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as a right-child of another node
 * @parent: A pointer to the parent node
 * @value: Value to store in new node
 * Return: Pointer to the new node, NULL upon failure
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *copy_right;

	if (!parent)
		return (NULL);

	if (!value)
		return (NULL);

	if (!parent->right)
		return (parent->right = binary_tree_node(parent, value));

	if (parent->right)
	{
		copy_right = parent->right;
		parent->right = binary_tree_node(parent, value);
		parent->right->right = copy_right;
		copy_right->parent = parent->right;
	}
	return (parent->right);
}
