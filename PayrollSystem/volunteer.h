#ifndef VOLUNTEER_H
#define VOLUNTEER_H

#include "person.h"

class Volunteer: public Person
{
public:
    Volunteer();
    ~Volunteer();

    QString getRole();

private:
    QString m_role;
};

#endif // VOLUNTEER_H
