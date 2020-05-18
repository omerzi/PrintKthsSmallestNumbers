#ifndef __LISTNODE_H
#define __LISTNODE_H
#include "Person.h"
class ListNode {
     friend class List;
private://members:
     Person *  m_PersonData;
     ListNode* m_NextNode;
public: //constructors:
     ListNode() = default;
     ListNode(Person * i_PersonData, ListNode * i_NextNode = nullptr);
     ~ListNode();
public://methods:
     Person *       GetPerson() const;
     ListNode *    GetNextListNode();
};
#endif 