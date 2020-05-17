#ifndef BSTreeNode__H
#define BSTreeNode__H
#include <iostream>
using namespace std;
class Person;

class BSTreeNode {

friend class BSTree;

private: // members:
	Person *     m_PersonData;
	BSTreeNode * m_Left, * m_Right;
public: // c'tor
	BSTreeNode(Person * i_PersonData, BSTreeNode * i_Left, BSTreeNode * i_Right);
public: // methods:
	Person * GetData() const;
	void     Inorder();
};
#endif // !BSTreeNode_H#
