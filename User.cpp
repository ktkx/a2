#include "User.h"

User::User()
{
}

User::User(string u,string p)
{
	userID = u;
	pass = p;	 
}

string User::getID()
{
	return userID;
}

string User::getPass()
{
	return pass;	
}

void User::setID (string id)
{
	userID = id;
}

bool User::getLocked()
{
	return locked;
}

void User::setLockedTrue()
{
	locked = true;
}

void User::setLockedFalse()
{
	locked = false;
}

