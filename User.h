// User.h
#include <string>
using namespace std;

class User {
	
	public:
		User();
		User(string,string);
		string getID();
		string getPass();
		void setID(string);
		bool getLocked();
		void setLockedTrue();
		void setLockedFalse();	 
		
	private:
		string userID;
		string pass;
		bool locked=false;
		
};

