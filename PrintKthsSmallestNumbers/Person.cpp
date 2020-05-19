#include "Person.h"
#pragma warning(disable:4996)

Person::Person(int i_ID, const string & i_Name)
{
	this->m_ID = i_ID;
	this->m_Name = i_Name;
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