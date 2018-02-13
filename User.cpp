#include "User.h"

User::User()
{
	locked = false;
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

bool User::getLock() {
	return locked;
}

void User::setID(string u) {
	userID = u;
}

void User::setPass(string p) {
	pass = p;
}

void User::setLock(bool l) {
	locked = l;
}

