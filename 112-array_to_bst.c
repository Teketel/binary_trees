#include "binary_trees.h"


/**
 * array_to_bst - build BST from an array
 * @array: array to convert to BST
 * @size: number of elements in array
 * Return: pointer to root of BST; NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i = 0;

	if (array == NULL)
		return (NULL);

	tree = bst_insert(&tree, array[i++]);

	while (i < size)
	{
		bst_insert(&tree, array[i]);
		i++;
	}
	return (tree);
}
