#include "person.h"

Person::Person()
{

}

Person::~Person()
{

}

int Person::getId()
{
    return m_id;
}

void Person::setFirstName(string fname)
{
    m_firstName = fname;
}

string Person::getFirstName()
{
    return m_firstName;
}

void Person::setLastName(string lname)
{
    m_lastName = lname;
}

string Person::getLastName()
{
    return m_lastName;
}

void Person::setAge(int age)
{
    m_age = age;
}

int Person::getAge()
{
    return m_age;
}

void Person::setPhoneNum(string phoneNum)
{
    m_phoneNum = phoneNum;
}

string Person::getPhoneNum() {
    return m_phoneNum;
}
