using namespace std;
#include <iostream>
#include <stdlib.h>

#include "Comparsions.h"
#include "BSTree.h"
#include "Person.h"
#include "List.h"

Comparsions::Comparsions(int i_ArraySize)
{
	this->m_ArraySize = i_ArraySize;
	this->m_PersonArray = new Person * [i_ArraySize];
}

Comparsions::~Comparsions()
{
	for(int i = 0; i < m_ArraySize; i++)
	{
		delete m_PersonArray[i];
	}
	delete [] m_PersonArray;
}

void Comparsions::ReadPersons()
{
	string name;
	int ID, personArraySize, k;
	cout << "Enter number of persons:" << endl;
	cin >> personArraySize;
	Comparsions instance(personArraySize);
	cout << "enter id and then name" << endl;
	for(int i = 0; i < personArraySize; i++)
	{
		cin >> ID;
		for(int j = 0; j < i; j++)
		{
			if(ID == instance.m_PersonArray[j]->GetID())
			{
				cout << "invaild input" << endl;
				exit(1);
			}
		}

		getchar();
		getline(cin, name);
		Person::CheckInputName(name);
		instance.m_PersonArray[i] = new Person(ID, name);
	}
	cout << "Enter the key ID value" << endl;
	cin >> k;
	instance.RunComparsions(instance.m_PersonArray, personArraySize, k);
}

void Comparsions::RunComparsions(Person ** i_PersonArray, int i_ArraySize, int k)
{
	cout << "NaivePrint: " << NaivePrint(i_PersonArray, i_ArraySize, k) << " comparsions" << endl;
	cout << "BSTPrint: " << BSTPrint(i_PersonArray, i_ArraySize, k) << " comparsions" << endl;
	cout << "PrintBySort: " << PrintBySort(i_PersonArray, i_ArraySize, k) << " comparsions" << endl; 
}

int Comparsions::NaivePrint(Person ** i_PersonArray, int n, int k)
{
	List personIdLessThenKey;
	int numComp = 0;
	for (int i = 0; i < n; i++)
	{
		int currentPersonId = i_PersonArray[i]->GetID();
		numComp++;
		if (currentPersonId < k)
		{
			ListNode * currentPersonNode = new ListNode(i_PersonArray[i]);
			personIdLessThenKey.SortedInsert(currentPersonNode, numComp);
		}
	}
	personIdLessThenKey.PrintList();
	return numComp;
}

int Comparsions::BSTPrint(Person ** i_PersonArray, int n, int k)
{
	int numComp = 0;
	BSTree binarySearchTree;
	for(int i = 0; i < n; i++)
	{
		binarySearchTree.Insert(i_PersonArray[i], numComp); //creating the BST from the array
	}

	binarySearchTree.PrintTreeByKey(k, numComp);
	return numComp;
}

int Comparsions::PrintBySort(Person ** i_PersonArray, int n, int k)
{
	int numComp = 0, i = 0;
	Quicksort(i_PersonArray, 0, n - 1, numComp);
	numComp++;
	while (i < n && i_PersonArray[i]->GetID() < k)
	{
		if (i != 0)
		{
			numComp++;
		}
		cout << i_PersonArray[i]->GetID() << " " << i_PersonArray[i]->GetName() << endl;
		i++;
	}

	return numComp;
}

int Comparsions::Partition(Person ** i_PersonArray, int i_StartingIndex, int i_EndingIndex, int & i_NumComp)
{
	//The partition algorithm takes the last element as pivot and places it in its correct position
	//The algorithms return the correct position index of the pivot
	int pivot = i_PersonArray[i_EndingIndex]->GetID();
	int smallerElement = i_StartingIndex - 1;
	for(int i = i_StartingIndex; i < i_EndingIndex; i++)
	{
		i_NumComp++; //comparsion made
		if(i_PersonArray[i]->GetID() <= pivot)
		{
			smallerElement++;
			swap(i_PersonArray[smallerElement], i_PersonArray[i]); //calling std method
		}
	}
	
	swap(i_PersonArray[smallerElement + 1], i_PersonArray[i_EndingIndex]);
	return smallerElement + 1;
}

void Comparsions::Quicksort(Person ** i_PersonArray, int i_StartingIndex, int i_EndingIndex, int & i_NumComp)
{
	//Implementation of Quicksort algorithm
	if(i_StartingIndex < i_EndingIndex)
	{
		int partitionIndex = Partition(i_PersonArray, i_StartingIndex, i_EndingIndex, i_NumComp);
		Quicksort(i_PersonArray, i_StartingIndex, partitionIndex - 1, i_NumComp);
		Quicksort(i_PersonArray, partitionIndex + 1, i_EndingIndex , i_NumComp);
	}
}
