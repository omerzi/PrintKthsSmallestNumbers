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
	m_PersonArray = new Person * [i_ArraySize];
}

Comparsions::~Comparsions()
{
	for (int i = 0; i < m_ArraySize; i++)
	{
		delete[] m_PersonArray[i];
	}
}

void Comparsions::ReadPersons()
{

}

int Comparsions::Partition(Person ** i_PersonArray, int i_StartingIndex, int i_EndingIndex)
{
	//The partition algorithm takes the last element as pivot and places it in its correct position
	//The algorithms return the correct position index of the pivot
	int pivot = i_PersonArray[i_EndingIndex]->GetID();
	int smallerElement = i_StartingIndex - 1;
	for(int i = 0; i < i_EndingIndex - 1; i++)
	{
		if(i_PersonArray[i]->GetID() <= pivot)
		{
			smallerElement++;
			swap(i_PersonArray[smallerElement], i_PersonArray[i]); //calling std method
		}
	}
	
	swap(i_PersonArray[smallerElement + 1], i_PersonArray[i_EndingIndex]);
	return smallerElement + 1;
}

void Comparsions::Quicksort(Person ** i_PersonArray, int i_StartingIndex, int i_EndingIndex)
{
	//Implementation of Quicksort algorithm
	if(i_StartingIndex < i_EndingIndex)
	{
		int partitionIndex = Partition(i_PersonArray, i_StartingIndex, i_EndingIndex);
		Quicksort(i_PersonArray, i_StartingIndex, partitionIndex - 1);
		Quicksort(i_PersonArray, partitionIndex + 1, i_EndingIndex);
	}
}
