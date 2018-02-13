// User.h
#include <string>
using namespace std;

class User {
	
	public:
		User();
		User(string,string);
//	  	  void login();
//	  	  void logout();
		bool locked;
		string getID();
		string getPass();	 
		
	private:
		string userID;
		string pass;
		
};

