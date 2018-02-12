#include "UserList.h"


UserList::UserList()
{	 
	//initialize vector users
	//read in from text file
	//if not valid, exits 
	fstream afile;
	afile.open("login.txt",ios::in);
	if (!afile)
	{
		cout << "Error reading file!" << endl;
		exit(-1);
	}
	
	int i = 0; 
	//User u;
	string user;
	string pass;
	while (!afile.eof())
	{
		getline(afile,user, ' ');	 
		getline(afile, pass,'\n');	  
		User u(user,pass);	  
		users.push_back(u);	   	   
	}
	
	afile.close();	  	  
}
		
bool UserList::validateUser(string u, string p)
{
	//iterate through array
	//match 	

	for (int i = 0; i < users.size();i++)
	{
		if ( (u == users[i].getPass()) && (p == users[i].getID()) )
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

