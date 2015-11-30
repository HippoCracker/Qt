#include "useraccount.h"

UserAccount::UserAccount(Employee *employee):
    m_employee(employee)
{

}

UserAccount::~UserAccount()
{

}

int UserAccount::getId()
{
    return m_id;
}

string UserAccount::getUsername()
{
    return m_username;
}

void UserAccount::setUsername(string username)
{
    m_username = username;
}

string UserAccount::getPassword()
{
    return m_password;
}

void UserAccount::setPassword(string password)
{
    m_password = password;
}

Employee* UserAccount::getEmployee()
{
    return m_employee;
}

void UserAccount::setEmployee(Employee *employee)
{
    m_employee = employee;
}
