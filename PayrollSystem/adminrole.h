#ifndef ADMINROLE_H
#define ADMINROLE_H

#include <QMainWindow>
#include "role.h"

class AdminRole: public Role
{
public:
    AdminRole();
    ~AdminRole();

    QMainWindow* createWorkArea();
};

#endif // ADMINROLE_H
