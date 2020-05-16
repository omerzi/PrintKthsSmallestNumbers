#ifndef BSTree__H
#define BSTree__H
#include "BSTreeNode.h"
typedef int Type;
class Person;

class BSTree {
private:
	BSTreeNode * root;
public:
	BSTree() {this->root = nullptr; };
	BSTree(BSTreeNode * root) { this->root = root; };
	~BSTree() { delete this->root; };
	BSTreeNode * Find(Type item);
	void Insert(Person * pers, int & NumComp);
	void Delete(Type item);
	void makeEmpty(BSTreeNode * root);
	bool isEmpty();
	BSTreeNode * parentFind(Type item);
	Type Min();
	BSTreeNode* Max();
	void PrintTree();
	BSTreeNode * getRoot() const;
	BSTreeNode * FindK(BSTreeNode * node, int k,int&NumComp);
	friend class BSTreeNode;
};
#endif // !BSTree_H