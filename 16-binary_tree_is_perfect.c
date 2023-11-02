#include "binary_trees.h"

/**
 * this_tree - function that checks if a tree is perfect or not
 * @tree: pointer to the root node of the tree to check.
 * @n: height of the current path in the tree.
 * @leaves: pointer to the tree's leaf count value.
 * @height: pointer to the tree's maximum height value.
 *
 * Return: no return.
 */
void this_tree(const binary_tree_t *tree, size_t n,
	size_t *leaves, size_t *height)
{
	if (tree != NULL)
	{
		if ((tree->left == NULL) && (tree->right == NULL))
		{
			if (leaves != NULL)
				(*leaves)++;
			if ((height != NULL) && (n > *height))
				*height = n;
		}
		else
		{
			this_tree(tree->left, n + 1, leaves, height);
			this_tree(tree->right, n + 1, leaves, height);
		}
	}
}
/**
 * binary_tree_is_perfect -  a function that checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check.
 * Return: 0 if trees is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t leaves_count = 0;
	size_t tree_height = 0;

	this_tree(tree, 0, &leaves_count, &tree_height);
	return ((int)leaves_count == (1 << tree_height) ? 1 : 0);
}



