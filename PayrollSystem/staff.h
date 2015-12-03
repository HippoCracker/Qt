#ifndef STAFF_H
#define STAFF_H

#include "person.h"

class Staff: public Person
{
public:
    Staff();
    ~Staff();

    QString getRole();

private:
    QString m_role;

};

#endif // STAFF_H
