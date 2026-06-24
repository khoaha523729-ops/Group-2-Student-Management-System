#include "Admin.h"
#include <iostream>

string Admin::getID() const
{
	return aId;
}

string Admin::getName() const
{
	return aName;
}

bool Admin::checkPassword(const string& inputPass) const 
{
    return aPass == inputPass;
}
