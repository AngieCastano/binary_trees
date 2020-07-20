#include "binary_trees.h"
/**
 * binary_tree_leaves - measures the ammount fo leaves in a binary tree
 * @tree: pointer to the root node of the tree whose leaves will be measured.
 * Return: No of leaves or 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	unsigned int leaf = 0;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	leaf += binary_tree_leaves(tree->left);
	leaf += binary_tree_leaves(tree->right);
	return (leaf);
}
