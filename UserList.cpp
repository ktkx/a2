#include "UserList.h"


UserList::UserList()
{
	//initialize vector users
	//read in from text file
	//if not valid, exits 
}
		
bool UserList::validateUser(string u, string p)
{
	//iterate through array
	//match 		
	for (int i = 0; i < users.size();i++)
	{
		if ( (u == users[i].getID()) && (p == users[i].getPass()) )
			return true;	
	}
	return false;	 	 
}

void UserList::lockAccount(string id)
{
	//use id to search in array if found 
	// then set locked in user record to true
	// else do nothing
	for (int i = 0; i < users.size();i++)
	{
		if (id == users[i].getID())
		{
			users[i].locked = true;
		}	 
	}	 
}

