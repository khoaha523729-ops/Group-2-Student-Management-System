#include <iostream>
#include <cctype>
#include "User.h"

using namespace std;

User::User(string uId, string uName, string uRole) : id(uId), name(uName), role(uRole)
{
	
}

string User::getID() const
{
	return id;
}

string User::getName() const
{
	return name;
}

string User::getRole() const
{
	return role;
}

bool User::setName(string n)
{
	if (n.empty())
	{
		cout << "Ten khong the de trong.\n";
		return false;
	}

	for (int i = 0; i < n.length(); i++) 
	{
		char c = n[i];
		if (std::isdigit(c) || (!isalpha(c) && c != ' ')) 
		{
			std::cout << "Ten khong the chua so hay ky tu dac biet.\n";
			return false;
		}
	}

	bool hoa = true;
	for (int i = 0; i < n.length(); i++)
	{
		if (n[i] == ' ')
		{
			hoa = true;
		}
		else
		{
			if (hoa)
			{
				n[i] = toupper(n[i]);
				hoa = false;
			}
			else
			{
				n[i] = tolower(n[i]);
			}
		}
	}
	name = n;
	return true;
}
