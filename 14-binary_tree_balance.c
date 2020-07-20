#include "binary_trees.h"
/**
 * binary_child_tree_height - measures the height of a child binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: height or 0 if tree is NULL
 */
int binary_child_tree_height(const binary_tree_t *tree)
{
	int h_left = 0, h_right = 0;

	if (!tree)
		return (0);

	h_left = binary_child_tree_height(tree->left);
	h_left++;
	h_right = binary_child_tree_height(tree->right);
	h_right++;
	if (h_left > h_right)
		return (h_left);
	else
		return (h_right);
}
/**
 * binary_tree_balance - measures the balance of a specific binary tree
 * @tree: pointer to the root node of the tree whose leaves will be measured.
 * Return: Returns balance of tree or NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int l_node = 0, r_node = 0;

	if (!tree)
		return (0);

	l_node = binary_child_tree_height(tree->left);
	r_node = binary_child_tree_height(tree->right);
	return (l_node - r_node);
}
