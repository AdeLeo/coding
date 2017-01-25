#include <stdio.h>

BinaryTreeNode *Construct(int *preorder, int *inorder, int length)
{
	if(preorder == NULL || inorder == NULL || length <= 0)
	{
		return NULL;
	}

	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + lenght - 1);
}

BinaryTreeNode * ConstructCore
(
	int *startPreorder, int *endPreorder,
	int *startinorder, int *endInorder
)
{
	int rootValue = startPreorder[0];
	BinaryTreeNode *root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->pRight = NULL;

	if(startPreorder == endPreorder)
	{
		if(startinorder == endInorder && *startPreorder == *startinorder)
			return root;
		else
			throw std::exception("Invalid input.");
	}

	int *rootInorder = startinorder;
	while(rootInorder <= endInorder && *rootInorder != rootValue)
		++ rootInorder;

	if(rootInorder == endInorder && *rootInorder != rootValue)
		throw std::exception("Invalid input.");

	int leftLength = rootInorder - startinorder;
	int *leftPreorderEnd = startPreorder + leftLength;
	if(leftLength > 0)
	{
		root->m_pLeft = ConstructCore(startPreorder + 1, 
			leftPreorderEnd, startPreorder, rootInorder - 1);
	}
	if(leftLength < endPreorder - startPreorder)
	{
		root->m_pRight = ConstructCore(leftPreorderEnd + 1,
			endPreorder, rootInorder + 1, endInorder);
	}

	return root;
}