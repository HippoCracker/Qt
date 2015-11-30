#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include "person.h"

using namespace std;

class Teacher: public Person
{
public:
    Teacher();
    ~Teacher();

    string getCollege();
    void setCollege(string college);

    string getDepartment();
    void setDepartment(string department);

private:
    string m_college;
    string m_department;
};

#endif // TEACHER_H
