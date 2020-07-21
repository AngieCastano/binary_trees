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

/**
 * printer - prints left and right branches of a root
 * @tree: pointer to the root of tree to print
 * @current_l: level of root to print
 * @func: function to print each node
 * Return: Nothing
 */

void printer(const binary_tree_t *tree, int current_l, void (*func)(int))
{
	if (!tree)
		return;

	if (current_l == 0)
		func(tree->n);

	else if (current_l > 0)
	{
		printer(tree->left, current_l - 1, func);
		printer(tree->right, current_l - 1, func);
	}
}

/**
 * binary_tree_levelorder - prints binary tree by levels
 * @tree: pointer to the root of tree to print
 * @func: function to print each node
 * Return: Nothing
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int h = 0, it = 0;

	if (!tree || !func)
		return;

	h = binary_tree_height(tree);

	while (it <= h)
	{
		printer(tree, it, func);
		it++;
	}
}
