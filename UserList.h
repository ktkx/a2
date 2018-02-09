// UserList.h
#include "User.h"
#include <vector>
using namespace std;

class UserList {
	
	public:
		UserList();
		bool validateUser();
		
		
		
	private:
		vector<User> users;
		void lockAccount();
};

