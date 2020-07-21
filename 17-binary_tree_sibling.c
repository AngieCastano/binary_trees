#include "binary_trees.h"
/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: node to check its sibiling
 * Return:  pointer to the sibling node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	if (node->parent->right && node->parent->right != node)
		return (node->parent->right);
	else if (node->parent->left && node->parent->left != node)
		return (node->parent->left);
	else
		return (NULL);
}
