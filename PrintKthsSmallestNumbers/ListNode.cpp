#include "ListNode.h"

ListNode::ListNode(Person * i_PersonData, ListNode* i_NextNode)
{
	this->m_PersonData = i_PersonData;
	this->m_NextNode = i_NextNode;
}

ListNode::~ListNode()
{
}

Person * ListNode::GetPerson() const
{
	return this->m_PersonData;
}

ListNode * ListNode::GetNextListNode()
{
	return this->m_NextNode;
}


