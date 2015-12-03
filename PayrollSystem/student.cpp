#include "student.h"

Student::Student():
    m_role("Student")
{

}

Student::~Student()
{

}

QString Student::getRole()
{
    return m_role;
}

QString Student::getCollege()
{
    return m_college;
}

void Student::setCollege(QString college)
{
    m_college = college;
}

QString Student::getMajor()
{
    return m_major;
}

void Student::setMajor(QString major)
{
    m_major = major;
}
