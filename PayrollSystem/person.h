#ifndef PERSON_H
#define PERSON_H

#include <QString>
using namespace std;

class Person
{
public:
    Person();
    ~Person();

    virtual QString getRole() = 0;

    int getId();

    void setFirstName(QString fname);
    QString getFirstName();

    void setLastName(QString lname);
    QString getLastName();

    void setAge(int age);
    int getAge();

    void setPhoneNum(QString phoneNum);
    QString getPhoneNum();


private:
    static int count;

    int m_id;
    QString m_firstName;
    QString m_lastName;
    int m_age;
    QString m_phoneNum;
};

#endif // PERSON_H
