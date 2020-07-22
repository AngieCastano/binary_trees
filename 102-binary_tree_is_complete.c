#include "binary_trees.h"
#include <stdio.h>
/**
 * binary_tree_is_complete_plus - auxiliar function for binary_tree_is_complete
 * @tree: tree to check
 * Return: 1 if is complete, else 0
 */
int binary_tree_is_complete_plus(const binary_tree_t *tree)
{
	int ret_left = 2, ret_right = 1;

	if (tree)
	{
		if (tree->right && !tree->left)
			return (0);
		if (tree->left && !tree->right)
			return (2);
		ret_left = binary_tree_is_complete_plus(tree->left);
		ret_right = binary_tree_is_complete_plus(tree->right);
		return (ret_left * ret_right);
	}
	return (1);
}
/**
 * binary_tree_is_complete -  checks if a binary tree is complete
 * @tree: tree to check
 * Return: 1 if is complete, else 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int ret_plus = 0;

	ret_plus = binary_tree_is_complete_plus(tree);
	if (ret_plus == 0 || ret_plus > 2)
		return (0);
	else
		return (1);
}
