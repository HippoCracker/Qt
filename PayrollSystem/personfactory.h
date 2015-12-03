#ifndef PERSONFACTORY_H
#define PERSONFACTORY_H

#include "person.h"

class PersonFactory
{
public:
    PersonFactory();
    ~PersonFactory();

    Person* getPerson(QString type);
    void freePerson(Person *person);

};

#endif // PERSONFACTORY_H
