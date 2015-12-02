#ifndef EMPLOYEEROLE_H
#define EMPLOYEEROLE_H

#include <QMainWindow>
#include "role.h"

class EmployeeRole: public Role
{
public:
    EmployeeRole();
    ~EmployeeRole();

    QMainWindow* createWorkArea();
    QString toString();
};

#endif // EMPLOYEEROLE_H
