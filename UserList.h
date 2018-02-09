// UserList.h

#include "User.h"

class UserList {
	
	public:
		UserList();
		bool validateUser();
		
		
		
	private:
		vector<User> users;
		void lockAccount();
};
