#include "ListNode.h"

ListNode::ListNode(int i_ComputerName, ListNode* i_NextNode)
{
	this->m_ComputerName = i_ComputerName;
	this->m_NextNode = i_NextNode;
}

ListNode::~ListNode()
{
}

int ListNode::GetCompNumber() const
{
	return this->m_ComputerName;
}

ListNode * ListNode::GetNextListNode()
{
	return this->m_NextNode;
}


