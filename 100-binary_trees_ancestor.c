#include "binary_trees.h"
/**
 * checker - checks the whole tree searching a special node
 * @root: root tree
 * @node_to_check: node to check
 * Return: 0 if it found it, 1 if it didn't
 */
int checker(const binary_tree_t *root, const binary_tree_t *node_to_check)
{
	int check_right = 1, check_left = 1;

	if (!root)
		return (1);
	check_right *= checker(root->right, node_to_check);
	check_left *= checker(root->left, node_to_check);
	if (root == node_to_check)
		return (0);
	else
		return (check_right * check_left);
}
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *traversal = NULL;
	int check = 1;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	if (first->left == second || first->right == second)
		return ((binary_tree_t *) first);
	if (second->left == first || second->right == first)
		return ((binary_tree_t *) second);
	traversal = (binary_tree_t *)first;
	while (check != 0)
	{
		if (traversal->parent)
		{
			traversal = traversal->parent;
			check = checker(traversal, second);
		}
		else
			check = 0;
	}
	if (check == 0)
		return (traversal);
	else
		return (NULL);
}
