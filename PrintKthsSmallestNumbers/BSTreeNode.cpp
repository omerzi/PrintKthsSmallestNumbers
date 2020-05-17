#include "BSTreeNode.h"
#include "Person.h"
BSTreeNode::BSTreeNode(Person * i_PersonData, BSTreeNode * i_i_Left, BSTreeNode * i_i_Right)
{
	this->m_PersonData = i_PersonData;
	this->m_Left = i_i_Left;
	this->m_Right = i_i_Right;
}

Person * BSTreeNode::GetData() const
{
	return this->m_PersonData;
}

void BSTreeNode::Inorder()
{
	if (this->m_Left != nullptr)
	{
		this->m_Left->Inorder();
	}
	cout << this->m_PersonData->GetID() << " " << this->m_PersonData->GetName();
	if (this->m_Right != nullptr)
	{
		this->m_Right->Inorder();
	}
}
