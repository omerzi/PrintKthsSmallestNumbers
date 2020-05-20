#include "Person.h"
#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <string>

Person::Person(int i_ID, const string & i_Name)
{
	this->m_ID = i_ID;
	this->m_Name = i_Name;
}

Person::~Person()
{
}

int Person::GetID() const
{
	return this->m_ID;
}

string & Person::GetName() 
{
	return this->m_Name;
}

void Person::SetID(int i_ID)
{
	this->m_ID = i_ID;
}

void Person::SetName(const string & i_Name)
{
	this->m_Name = i_Name;
}


void Person::CheckInputName(const string & i_Name)
{
	int personLengthName = i_Name.length();
	int spaceCounter = 0;
	for (int j = 0; j < personLengthName; j++)
	{
		if(!(i_Name[j] >= 'a' && i_Name[j] <= 'z' || i_Name[j] >= 'A' && i_Name[j] <= 'Z' || i_Name[j] == ' '))
		{
			cout << "invaild input" << endl;
			exit(1);
		}
		if (i_Name[j] == ' ' && (j == 0 || j == personLengthName - 1))
		{
			cout << "invaild input" << endl;
			exit(1);
		}
		if (i_Name[j] == ' ')
		{
			spaceCounter++;
		}
	}
	if (spaceCounter > 1)
	{
		cout << "invaild input" << endl;
		exit(1);
	}
}
