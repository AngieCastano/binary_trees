#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: height or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	unsigned int h_left = 0, h_right = 0;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	h_left = binary_tree_height(tree->left);
	h_left++;
	h_right =  binary_tree_height(tree->right);
	h_right++;
	if (h_left > h_right)
		return (h_left);
	else
		return (h_right);
}
