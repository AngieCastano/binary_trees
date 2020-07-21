#include "binary_trees.h"
/**
 * binary_tree_nodes - measures the ammount of nodes with 1 child
 * in a binary tree
 * @tree: pointer to the root node of the tree whose leaves will be measured.
 * Return: No of sole childs or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	unsigned int l_node = 0, r_node = 0;

	if (!tree)
		return (0);

	if (tree->left || tree->right)
	{
		l_node = 1 + binary_tree_nodes(tree->left);
		r_node = 1 +  binary_tree_nodes(tree->right);
		return (l_node + r_node - 1);

	}
	else
		return (0);
}
