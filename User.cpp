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

/*	  	  
void User::login()
{

}
		
void User::logout()
{
	
}
*/

string User::getID()
{
	return userID;
}

string User::getPass()
{
	return pass;	
}

