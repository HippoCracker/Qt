#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

using namespace std;


class Student: public Person
{
public:
    Student();
    ~Student();

    QString getCollege();
    void setCollege(QString college);

    QString getMajor();
    void setMajor(QString major);

    QString getRole();

private:
    QString m_college;
    QString m_major;
    QString m_role;

};

#endif // STUDENT_H
