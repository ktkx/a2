// UserList.h
#include "User.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class UserList {
	
	public:
		UserList();
		bool validateUser(string,string); 
		
	private:
		vector<User> users;
};

