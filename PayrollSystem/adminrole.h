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
    QString toString();
};

#endif // ADMINROLE_H
