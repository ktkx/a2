#include "User.h"

User::User()
{
	locked = false;
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

