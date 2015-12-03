#include "executive.h"

Executive::Executive():
    m_role("Executive")
{

}

Executive::~Executive()
{

}

QString Executive::getRole()
{
    return m_role;
}
