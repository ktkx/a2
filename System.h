// System.h

#include "StockList.h"
#include "UserList.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

class System {
	
	public:
		System();
		void readFile();
		void encryptData();
		void decryptData();
		void displayLogin();
		void displayFail(){cout<<"Invalid Username or Password!" << endl;};
		int displayMainMenu();
		void displayEditDetails();
		
	private:
		StockList listOfStock;
		UserList listOfUser;	
};

