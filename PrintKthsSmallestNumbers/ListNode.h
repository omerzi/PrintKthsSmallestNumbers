#ifndef __LISTNODE_H
#define __LISTNODE_H
class ListNode {
     friend class List;
private://members:
     int       m_ComputerName;
     ListNode* m_NextNode;
public: //constructors:
     ListNode() = default;
     ListNode(int i_ComputerName, ListNode* i_NextNode = nullptr);
     ~ListNode();
public://methods:
     int       GetCompNumber() const;
     ListNode *    GetNextListNode();
};
#endif 