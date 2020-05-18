#ifndef __LIST_H
#define __LIST_H
#include "ListNode.h"
class Person;
class List
{
private: //members:
	ListNode * m_Head;
	ListNode * m_Tail;
public: //constructors:
	 List();
	~List();
public: // methods:
	void	   MakeEmpty();
	void	   InsertAfter(ListNode * i_Node, ListNode * i_NodeToInsertAfter);
	void	   DeleteNode(ListNode * i_Node);
	void	   sortedInsert(ListNode * i_NewNode);
	bool	   IsEmpty();
	ListNode * First();
	ListNode * Last();
	ListNode * FindPrevNode(ListNode * i_Node);
	ListNode * FindNode(int i_ID);
	int		   Size();
};
#endif // !__LIST_H



