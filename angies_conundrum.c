#include "binary_trees.h"
#include <stdio.h>
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
 * until_perfect - checks number of nodes where tree should be perfect
 * @input: size of tree
 * Return: Number of nodes that tree should have to be perfect
 */
int until_perfect(int input)
{
	int a = 1, b = 0, c = 0;
	while(c < input)
	{
		c += b;
		b = a;
		a <<= 1;
	}
	if (c > input)
		c>>= 1;

	return (c);
}

int to_check(int nodes_to_perf)
{
	int i = 0;

	while(nodes_to_perf > 0)
	{
		nodes_to_perf>>= 1;
		i++;
	}
	return (i);
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
 * printer - prints left and right branches of a root
 * @tree: pointer to the root of tree to print
 * @current_l: level of root to print
 * @func: function to print each node
 * Return: Nothing
 */

int printer(const binary_tree_t *tree, int current_l, int num_rec,
	    int level_to_check)
{
	int ret_left = 1, ret_right = 1;

	if (!tree)
		return (1);
	if (current_l == 0 && num_rec == level_to_check)
	{
		if (tree->right)
		{
			ret_left = 2;
			if (tree->left)
				ret_left *= 2;
		}
		return (ret_left);
	}
	if (current_l > 0)
	{
		ret_left = printer(tree->left, current_l - 1, num_rec + 1,
				   level_to_check);
		ret_right = printer(tree->right, current_l - 1, num_rec + 1,
				    level_to_check);
	}
	return (ret_left * ret_right);
}
/**
 * binary_tree_levelorder - prints binary tree by levels
 * @tree: pointer to the root of tree to print
 * @func: function to print each node
 * Return: Nothing
 */

int _binary_tree_levelorder(const binary_tree_t *tree, int level_to_check)
{
        int h = 0, it = 0, pr_help;

        if (!tree)
                return (0);

        h = binary_tree_height(tree);

        while (it <= h)
        {
		pr_help = printer(tree, it, 1, level_to_check);
		if (pr_help > 1)
			return (pr_help);
                it++;
        }
	return (1);
}

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int size = 0, residue = 0, nodes_to_perf = 0,
		level_to_check = 0, is_res = 0;

	if (!tree)
		return (0);

	size = binary_tree_size(tree);
	nodes_to_perf = until_perfect(size);
	residue = size - nodes_to_perf;

	level_to_check = to_check(nodes_to_perf);

	is_res = _binary_tree_levelorder(tree, level_to_check);

	printf("is_res - %i residue - %i\n", is_res, residue);

	return (is_res);
}
