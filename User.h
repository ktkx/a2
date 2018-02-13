// User.h
#include <string>
using namespace std;

class User {
	
	public:
		User();
		User(string,string);
		
		string getID();
		string getPass();	 
		bool getLock();
		
		void setID(string);
		void setPass(string);
		void setLock(bool);

		
	private:
		string userID;
		string pass;
		bool locked;
};

