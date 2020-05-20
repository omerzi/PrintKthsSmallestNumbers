#ifndef BSTree__H
#define BSTree__H
#include "BSTreeNode.h"
typedef int Type;
class Person;

class BSTree {
friend class BSTreeNode;

private: //members:
	BSTreeNode * m_Root;
public: //c'tors:
	BSTree() {this->m_Root = nullptr; };
	BSTree(BSTreeNode * i_Root) {this->m_Root = i_Root; };
	~BSTree();
public: //methods
	BSTreeNode * Find(Type i_KeyID);
	BSTreeNode * GetRoot() const;
	BSTreeNode * ParentFind(Type i_KeyID);
	void         Insert(Person * i_Person, int & i_NumComp);
	void         Delete(BSTreeNode * i_Node, int i_KeyID);
	void         MakeEmpty(BSTreeNode * i_Root);
	void         PrintTree();
	void		 Dispose(BSTreeNode * i_Root);
	void		 PrintTreeByKey(int i_Key, int & i_NumComp);
	bool         IsEmpty();
	BSTreeNode * Min(BSTreeNode * i_Node);
	BSTreeNode * Max(BSTreeNode * i_Node);
};
#endif // !BSTree_H