#include "personfactory.h"
#include "student.h"
#include "teacher.h"
#include "staff.h"
#include "executive.h"
#include "volunteer.h"

PersonFactory::PersonFactory()
{

}

PersonFactory::~PersonFactory()
{

}

Person* PersonFactory::getPerson(QString type)
{
    Person *person = 0;
    if (type == "Student") {
        person = new Student();
    } else if (type == "Teacher") {
        person = new Teacher();
    } else if (type == "Executive") {
        person = new Executive();
    } else if (type == "Volunteer") {
        person = new Volunteer();
    } else {
        person = new Staff();
    }

    return person;
}

void freePerson(Person *person)
{
    delete person;
}
