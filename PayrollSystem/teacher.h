#ifndef TEACHER_H
#define TEACHER_H

#include "person.h"

using namespace std;

class Teacher: public Person
{
public:
    Teacher();
    ~Teacher();

    QString getCollege();
    void setCollege(QString college);

    QString getDepartment();
    void setDepartment(QString department);

    QString getRole();

private:
    QString m_college;
    QString m_department;
    QString m_role;

};

#endif // TEACHER_H
