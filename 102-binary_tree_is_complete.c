#include "binary_trees.h"
#include <stdio.h>
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
 * @num_rec: just another variable
 * Return: Nothing
 */

int printer(const binary_tree_t *tree, int current_l, int *num_rec)
{
	int ret_left = 1, ret_right = 1;

	if (!tree)
		return (1);
	if (current_l == 0)
	{
		++num_rec;
		if (tree->parent)
			if (tree->parent->left == tree && !tree->parent->right)
			{
				return (2);
			}
		if (tree->right && !tree->left)
			return (3);
	}
	if (current_l > 0)
	{
		ret_left = printer(tree->left, current_l - 1, num_rec);
		ret_right = printer(tree->right, current_l - 1, num_rec);
	}
	return (ret_left * ret_right);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root of tree to print
 * Return: Nothing
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int h = 0, it = 0, ret_printer = 0, uno = 1;
	int *num_rec = &uno;

	if (!tree)
		return (0);

	h = binary_tree_height(tree);

	while (it <= h)
	{
		ret_printer = printer(tree, it, num_rec);
		if (ret_printer > 2)
			return (0);
		it++;
	}
	return (1);
}
