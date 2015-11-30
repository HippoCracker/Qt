#include "teacher.h"

Teacher::Teacher()
{

}

Teacher::~Teacher()
{

}

string Teacher::getCollege()
{
    return m_college;
}

void Teacher::setCollege(string college)
{
    m_college = college;
}

string Teacher::getDepartment()
{
    return m_department;
}

void Teacher::setDepartment(string department)
{
    m_department = department;
}
