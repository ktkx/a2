// User.h
#pragma once
#include <string>
using namespace std;

class User {
	
	public:
		User();
//	  	  void login();
//	  	  void logout();
		bool locked;
		string getID();
		string getPass();
		
	private:
		string userID;
		string pass;
		
};

