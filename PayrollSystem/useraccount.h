#ifndef USERACCOUNT_H
#define USERACCOUNT_H

#include <string>
#include "employee.h"


using namespace std;

class UserAccount
{
public:
    UserAccount(Employee *employee);
    ~UserAccount();

    int getId();

    string getUsername();
    void setUsername(string username);

    string getPassword();
    void setPassword(string password);

    Employee* getEmployee();
    void setEmployee(Employee *employee);

private:
    int m_id;
    string m_username;
    string m_password;
    Employee *m_employee;
};

#endif // USERACCOUNT_H
