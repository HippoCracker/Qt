#include "teacher.h"

Teacher::Teacher():
    m_role("Teacher")
{

}

Teacher::~Teacher()
{

}

QString Teacher::getCollege()
{
    return m_college;
}

void Teacher::setCollege(QString college)
{
    m_college = college;
}

QString Teacher::getDepartment()
{
    return m_department;
}

void Teacher::setDepartment(QString department)
{
    m_department = department;
}

QString Teacher::getRole()
{
    return m_role;
}
