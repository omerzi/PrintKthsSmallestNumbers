#include "Person.h"
#pragma warning(disable:4996)
#include <iostream>
#include <cctype>
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
	bool isFirstAndLastName = false;
	for(int j = 1; j < personLengthName - 1 && !isFirstAndLastName; j++)
	{ // check if the is a first name space last name sequence
		isFirstAndLastName = i_Name[j] == ' '&& isalpha(i_Name[j - 1]) && isalpha(i_Name[j + 1]);
	}
	if(!isFirstAndLastName)
	{
		cout << "invalid input";
		exit(1);
	}
}
