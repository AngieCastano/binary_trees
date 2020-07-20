#include "binary_trees.h"
/**
 * binary_tree_is_full - checks if binary tree is full
 * @tree: pointer to the root node of the tree whose leaves will be measured.
 * Return: 1 if full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int l_node = 1, r_node = 1;

	if (!tree)
		return (1);

	if (!tree->left ^ !tree->right)
		return (0);

	l_node *= binary_tree_is_full(tree->left);
	r_node *= binary_tree_is_full(tree->right);

	return (l_node * r_node);
}
