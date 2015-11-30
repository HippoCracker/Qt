#ifndef ROLE_H
#define ROLE_H

#include <QMainWindow>

class Role
{
public:
    Role();
    virtual ~Role();
    virtual QMainWindow* createWorkArea() = 0;
};

#endif // ROLE_H
