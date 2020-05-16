#include "BSTreeNode.h"
BSTreeNode::BSTreeNode(Person * data, int numOfSons, BSTreeNode * left, BSTreeNode * right)
{
	this->data = data;
	this->left = left;
	this->right = right;
	this->numOfSons = numOfSons;
}

BSTreeNode::~BSTreeNode()
{
	delete this->left;
	delete this->right;
}

Person * BSTreeNode::getData() const
{
	return this->data;
}

void BSTreeNode::inorder()
{
	if (this->left != nullptr)
		this->left->inorder();
	cout << this->data;
	if (this->right != nullptr)
		this->right->inorder();
}

void BSTreeNode::preorder()
{
	cout << this->data;
	if (this->left != nullptr)
		this->left->preorder();
	if (this->right != nullptr)
		this->right->preorder();
}

void BSTreeNode::postorder()
{
	if (this->left != nullptr)
		this->left->postorder();
	if (this->right != nullptr)
		this->right->postorder();
	cout << this->data;
}
