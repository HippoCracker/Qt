#include "student.h"

Student::Student()
{

}

Student::~Student()
{

}

string Student::getCollege()
{
    return m_college;
}

void Student::setCollege(string college)
{
    m_college = college;
}

string Student::getMajor()
{
    return m_major;
}

void Student::setMajor(string major)
{
    m_major = major;
}
