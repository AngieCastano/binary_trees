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
/**
 * binary_tree_is_perfect - Checks if binary tree is perfect
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: 1 if is perfect, 0 if NULL or not
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	unsigned int nodes = 0, height = 0, expected_nodes = 1;

	if (!tree)
		return (0);

	height = binary_tree_height(tree);
	nodes = binary_tree_size(tree);

	expected_nodes <<= height + 1;
	expected_nodes -= 1;

	if (nodes == expected_nodes)
		return (1);
	else
		return (0);
}
