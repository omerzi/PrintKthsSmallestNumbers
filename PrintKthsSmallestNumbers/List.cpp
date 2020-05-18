#include "List.h"

List::List()
{
	MakeEmpty();
}

List::~List()
{
	ListNode* current = m_Head;
	ListNode* tempNode;
	while (current != nullptr)
	{
		tempNode = current->m_NextNode;
		delete current;
		current = tempNode;
	}
}

void List::MakeEmpty()
{
	this->m_Head = nullptr;
	this->m_Tail = nullptr;
}

bool List::IsEmpty()
{
	if (this->m_Head == nullptr)
	{
		return true;
	}
	return false;
}

ListNode * List::First()
{
	return this->m_Head;
}

ListNode * List::Last()
{
	return this->m_Tail;
}

ListNode * List::FindPrevNode(ListNode * i_Node)
{
	ListNode * currentNode = this->m_Head;
	while (currentNode)
	{
		if (currentNode->m_NextNode == i_Node)
		{
			return currentNode;
		}
		currentNode = currentNode->m_NextNode;
	}
	return nullptr;
}

ListNode * List::FindNode(int i_ID)
{
	ListNode * currentNode = this->m_Head;
	while (currentNode)
	{
		if (currentNode->m_PersonData->GetID() == i_ID)
		{
			return currentNode;
		}
		currentNode = currentNode->m_NextNode;
	}

	return nullptr;
}

void List::InsertAfter(ListNode * i_Node, ListNode* i_NodeToInsertAfter)
{
	if (IsEmpty())
	{
		this->m_Head = this->m_Tail = i_Node;
	}
	else 
	{
		ListNode* tempNode = i_NodeToInsertAfter->GetNextListNode();
		i_NodeToInsertAfter->m_NextNode = i_Node;
		i_Node->m_NextNode = tempNode;
		if (i_Node == this->m_Tail)
		{
			this->m_Tail = i_NodeToInsertAfter;
		}
	}
}


void List::DeleteNode(ListNode * i_Node)
{
	if (this->m_Head == i_Node)
	{
		this->m_Head = i_Node->m_NextNode;
		i_Node->m_NextNode = nullptr;
	}
	else 
	{
		ListNode * prevNode = FindPrevNode(i_Node);
		prevNode->m_NextNode = i_Node->m_NextNode;
		i_Node->m_NextNode = nullptr;
		if (this->m_Tail == i_Node)
		{
			this->m_Tail = prevNode;
		}
	}
	if (this->m_Head == nullptr)
		this->m_Head = this->m_Tail = nullptr;
	delete i_Node;
}

int List::Size()
{
	int listSize = 0;
	ListNode * currentNode = this->m_Head;
	while (!IsEmpty())
	{
		listSize++;
		currentNode = currentNode->m_NextNode;
	}
	return listSize;
}

void List::sortedInsert(ListNode * i_newNode)
{
	ListNode* current;
	int inputPersonID = i_newNode->GetPerson()->GetID();
	if (this->m_Head == NULL || m_Head->GetPerson()->GetID() >= inputPersonID)
	{
		if (m_Head == NULL)
		{
			this->m_Tail = i_newNode;
		}
		i_newNode->m_NextNode = m_Head;
		this->m_Head = i_newNode;
		
		
	}
	else
	{
		current = m_Head;
		while (current->GetNextListNode() != NULL && current->GetNextListNode()->GetPerson()->GetID() < inputPersonID)
		{
			current = current->GetNextListNode();
		}
		i_newNode->m_NextNode = current->GetNextListNode();
		current->m_NextNode = i_newNode;
		if (i_newNode->GetNextListNode() == nullptr)
		{
			m_Tail = i_newNode;
		}
	}
}



