#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "person.h"

class Executive: public Person
{
public:
    Executive();
    ~Executive();

    QString getRole();

private:
    QString m_role;
};

#endif // EXECUTIVE_H
