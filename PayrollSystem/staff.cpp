#include "staff.h"

Staff::Staff():
    m_role("Staff")
{

}

Staff::~Staff()
{

}

QString Staff::getRole()
{
    return m_role;
}
