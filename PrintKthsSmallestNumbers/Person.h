#ifndef PERSON__H
#define PERSON__H
#include <string>
using namespace std;

class Person {
private:
	unsigned int m_ID;
	string       m_Name;
public:
	Person(int i_ID, string i_Name);
	Person(Person & other);
	~Person();
	const int getID() const;
	char * getName() const;
	void setID(const int id);
	void setName(const char * name);
public:
	void operator=(const Person & other);

};
#endif // !PERSON_H