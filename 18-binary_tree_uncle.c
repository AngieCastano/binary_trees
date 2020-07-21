#include "binary_trees.h"
/**
 * binary_tree_uncle - finds the sibling of a node
 * @node: node to check its sibiling
 * Return:  pointer to the sibling node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node)
		return (NULL);
	if (!node->parent)
		return (NULL);
	if (!node->parent->parent)
		return (NULL);
	if (!node->parent->parent->right && !node->parent->parent->left)
		return (NULL);
	if (node->parent->parent->right && node->parent->parent->right
	    != node->parent)
		return (node->parent->parent->right);
	else if (node->parent->parent->left && node->parent->parent->left
		 != node->parent)
		return (node->parent->parent->left);
	else
		return (NULL);
}
