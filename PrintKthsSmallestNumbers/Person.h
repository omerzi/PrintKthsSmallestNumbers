#ifndef PERSON__H
#define PERSON__H
#include <string>
using namespace std;

class Person {
private: // members:
	int			 m_ID;
	string       m_Name;
public: // c'tor:
	Person(int i_ID, const string & i_Name);
public: //methods:
	int      GetID() const;
	string & GetName();
	void     SetID(int i_ID);
	void     SetName(const string & i_Name);
};
#endif // !PERSON_H