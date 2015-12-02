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

void Person::setFirstName(QString fname)
{
    m_firstName = fname;
}

QString Person::getFirstName()
{
    return m_firstName;
}

void Person::setLastName(QString lname)
{
    m_lastName = lname;
}

QString Person::getLastName()
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

void Person::setPhoneNum(QString phoneNum)
{
    m_phoneNum = phoneNum;
}

QString Person::getPhoneNum() {
    return m_phoneNum;
}
