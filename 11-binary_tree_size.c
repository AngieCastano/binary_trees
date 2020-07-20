#include "binary_trees.h"
/**
 * binary_tree_size - measures the szie of a binary tree
 * @tree: pointer to the root node of the tree to measure the size.
 * Return: size or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	unsigned int h_left = 0, h_right = 0;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	h_left = binary_tree_size(tree->left);
	h_left++;
	h_right = binary_tree_size(tree->right);
	h_right++;
	return (h_left + h_right - 1);
}
