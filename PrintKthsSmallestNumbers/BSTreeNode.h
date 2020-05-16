#ifndef BSTreeNode__H
#define BSTreeNode__H
#include <iostream>
using namespace std;
class Person;

class BSTreeNode {

private:
	int numOfSons;
	Person * data;
	BSTreeNode * left, *right;
public:
	BSTreeNode() {this->numOfSons = 0;	};
	BSTreeNode(Person * data, int numOfSons,BSTreeNode * left, BSTreeNode * right);
	~BSTreeNode() ;
	Person * getData() const;
	void inorder();
	void preorder();
	void postorder();
	friend class BSTree;

};
#endif // !BSTreeNode_H#
