// System.h

#include "StockList.h"
#include "UserList.h"


class System {
	
	public:
		System();
		void encryptData();
		void decryptData();
		void displayLogin();
		void displayFail(){cout<<"Invalid Username or Password!" << endl;};
		int displayMainMenu();
		void displayEditDetails();
		
	private:
		//StockList listOfStock;
		//UserList listOfUser;
		
};

