#include "volunteer.h"

Volunteer::Volunteer():
    m_role("Volunteer")
{

}

Volunteer::~Volunteer()
{

}

QString Volunteer::getRole()
{
    return m_role;
}
