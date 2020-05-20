#ifndef __COMPARSIONS_H
#define __COMPARSIONS_H

class List;
class Person;
class BSTree;

class Comparsions
{
private: //members:
	Person ** m_PersonArray;
	int		  m_ArraySize;
public: //c'tor & d'tor
	Comparsions(int i_ArraySize);
	~Comparsions();
public: //static methods:
	static void ReadPersons();
public: //methods:
    void RunComparsions(Person ** i_PersonArray, int i_ArraySize, int k);
	int NaivePrint(Person ** i_PersonArray, int n, int k);
	int BSTPrint(Person ** i_PersonArray, int n, int k);
	int PrintBySort(Person** i_PersonArray, int n, int k);
	int Partition(Person ** i_PersonArray, int i_StartingIndex, int i_EndingIndex, int & i_NumComp);
	void Quicksort(Person ** i_PersonArray, int i_StartingIndex, int i_EndingIndex, int & i_NumComp);
};
#endif // !__COMPARSIONS_H



