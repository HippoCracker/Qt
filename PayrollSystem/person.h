#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
public:
    Person();
    ~Person();

//    virtual createWorkArea() = 0;

    int getId();

    void setFirstName(string fname);
    string getFirstName();

    void setLastName(string lname);
    string getLastName();

    void setAge(int age);
    int getAge();

    void setPhoneNum(string phoneNum);
    string getPhoneNum();


private:
    int m_id;
    string m_firstName;
    string m_lastName;
    int m_age;
    string m_phoneNum;
};

#endif // PERSON_H
