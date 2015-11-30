#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "person.h"

using namespace std;


class Student: public Person
{
public:
    Student();
    ~Student();

    string getCollege();
    void setCollege(string college);

    string getMajor();
    void setMajor(string major);

private:
    string m_college;
    string m_major;

};

#endif // STUDENT_H
