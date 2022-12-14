#include "binary_trees.h"


int binary_tree_balance(const binary_tree_t *tree);
size_t recurse_for_height(const binary_tree_t *tree);
int recurse_for_balance(const binary_tree_t *tree);


/**
 * binary_tree_is_perfect - checks for perfect binary tree
 * @tree: pointer to the root node
 * Description: 16. Is perfect
 * Return: see below
 * 1. upon success, return 1
 * 2. upon fail, return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (recurse_for_balance(tree) == 0)
		return (1);
	return (0);
}
/**
 * recurse_for_balance - utility for checking tree and subtrees
 * @tree: pointer to root of tree
 * Return: balance factor
 */
int recurse_for_balance(const binary_tree_t *tree)
{
	int balFactor;

	if (!tree)
		return (0);

	balFactor = binary_tree_balance(tree);

	if (balFactor != 0)
		return (balFactor);

	return (recurse_for_balance(tree->left) || recurse_for_balance(tree->right));
}
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to node to measure the balance factor
 * Description: 14. Balance factor
 * Return: see below
 * 1. upon success, return balance factor
 * 2. upon fail, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0;
	int right = 0;

	if (tree == NULL)
		return (0);

	/* if given node has no balance factor */
	if ((tree->left == NULL) && (tree->right == NULL))
	{
		return (0);
	}

	left = recurse_for_height(tree->left) - 1;
	right = recurse_for_height(tree->right) - 1;

	return (left - right);
}
/**
 * recurse_for_height - measure height
 * @tree: tree to measure
 * Return: height
 */
size_t recurse_for_height(const binary_tree_t *tree)
{
	size_t heightR, heightL;

	if (!tree)
		return (0);

	heightL = recurse_for_height(tree->left);
	heightR = recurse_for_height(tree->right);

	if (heightL > heightR)
		return (heightL + 1);
	else
		return (heightR + 1);
}
