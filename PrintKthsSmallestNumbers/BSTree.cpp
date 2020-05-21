#include "BSTree.h"
#include "BSTreeNode.h"
#include "Person.h"
#include <iostream>

BSTree::~BSTree()
{
	//call recurisve delete method:
	Dispose(m_Root);
}

BSTreeNode * BSTree::Find(Type i_KeyID)
{ //find the node of by the type given
	BSTreeNode * currentNode = this->m_Root;
	while(currentNode != nullptr && currentNode->GetData()->GetID() != i_KeyID)
	{
		if(i_KeyID < currentNode->m_PersonData->GetID())
		{
			currentNode = currentNode->m_Left;
		}
		else if(i_KeyID > currentNode->m_PersonData->GetID())
		{
			currentNode = currentNode->m_Right;
		}
	}

	return currentNode;
}

void BSTree::Insert(Person * i_Person, int & i_NumComp)
{
	i_NumComp++; // a comparsion made
	BSTreeNode * currentNode = this->m_Root;
	BSTreeNode * parentNode = nullptr;
	BSTreeNode * newNode;
	while(currentNode != nullptr)
	{
		parentNode = currentNode;
		i_NumComp++; // a comparsion made
		if(i_Person->GetID() < currentNode->m_PersonData->GetID())
		{
			currentNode = currentNode->m_Left;
		}
		else
		{
			currentNode = currentNode->m_Right;
		}
	}

	newNode = new BSTreeNode(i_Person, nullptr, nullptr);
	if(parentNode == nullptr) // insert newNode as root
	{
		i_NumComp++; // a comparsion made
		this->m_Root = newNode;
	}
	else if(i_Person->GetID() < parentNode->m_PersonData->GetID())
	{
		i_NumComp++; // a comparsion made
		parentNode->m_Left = newNode; //insert newNode as left child
	}
	else
	{
		i_NumComp++; // a comparsion made
		parentNode->m_Right = newNode; // insert newNode as right child
	}
}

void BSTree::Delete(BSTreeNode * i_Node, int i_KeyID)
{
	if(i_Node != nullptr)
	{
		if(i_Node->GetData()->GetID() < i_KeyID)
		{
			Delete(i_Node->m_Left, i_KeyID);
		}
		else if(i_Node->GetData()->GetID() > i_KeyID)
		{
			Delete(i_Node->m_Right, i_KeyID);
		}
		else if(i_Node->m_Left != nullptr && i_Node->m_Right != nullptr)
		{
			BSTreeNode* minNode = Min(i_Node->m_Right);
			i_Node->m_PersonData = minNode->m_PersonData;
			Delete(i_Node->m_Right, i_Node->GetData()->GetID());
		}
		else
		{
			BSTreeNode* tempNode = i_Node;
			if(i_Node->m_Left == nullptr)
			{
				i_Node = i_Node->m_Right;
			}
			else if (i_Node->m_Right == nullptr)
			{
				i_Node = i_Node->m_Left;
			}

			delete tempNode;
		}
	}
}

void BSTree::MakeEmpty(BSTreeNode * i_Root)
{
	if(i_Root != nullptr)
	{
		if (i_Root->m_Left != nullptr)
		{
			MakeEmpty(i_Root->m_Left);
		}
		if (i_Root->m_Right != nullptr)
		{
			MakeEmpty(i_Root->m_Right);
		}
		delete i_Root;
	}
}

bool BSTree::IsEmpty()
{
	return this->m_Root == nullptr;
}

BSTreeNode * BSTree::ParentFind(Type i_KeyID)
{
	//find the parent of node by the type given
	BSTreeNode * tempNode = this->m_Root;
	while(tempNode != nullptr)
	{
		if(i_KeyID == tempNode->m_Left->GetData()->GetID())
		{
			return tempNode;
		}
		else if(i_KeyID == tempNode->m_Right->m_PersonData->GetID())
		{
			return tempNode;
		}
		else if(i_KeyID < tempNode->m_PersonData->GetID())
		{
			tempNode = tempNode->m_Left;
		}
		else
		{
			tempNode = tempNode->m_Right;
		}
	}

	return nullptr;
}

BSTreeNode * BSTree::Min(BSTreeNode * i_Node)
{ //return the minimum value in the tree
	if(i_Node != nullptr && i_Node->m_Left != nullptr)
	{
		Min(i_Node->m_Left);
	}
	
	return i_Node;
}

BSTreeNode * BSTree::Max(BSTreeNode * i_Node)
{ // return the max value in the tree
	if(i_Node != nullptr && i_Node->m_Right != nullptr)
	{
		Max(i_Node->m_Right);
	}

	return i_Node;
}

void BSTree::PrintTree()
{
	//prints the tree in Inorder
	if(this->m_Root != nullptr)
	{
		this->m_Root->Inorder();
	}
}

void BSTree::Dispose(BSTreeNode* i_Root)
{
	if (i_Root != nullptr)
	{
		Dispose(i_Root->m_Left);
		Dispose(i_Root->m_Right);
		delete i_Root;
	}
}

void BSTree::PrintTreeByKey(int i_Key, int & i_NumComp)
{
	if(this->m_Root != nullptr)
	{
		this->m_Root->InorderSmallerThanKey(i_Key, i_NumComp);
	}
}

BSTreeNode * BSTree::GetRoot() const
{
	return this->m_Root;
}
