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
		if ( (p == users[i].getPass()) && (u == users[i].getID()) )
			return true;	
	}	  
	return false;	 	 
}

