// System.h
#pragma once

#include "StockList.h"
#include "UserList.h"
#include <fstream>
#include <iostream>
#include <vector>
//#include <unistd.h>
using namespace std;

class System {
	
	public:
		System();
		string encryptData(string);
		string decryptData(string);

		void displayLogin();
		void displayFail(){cout<<"Invalid Username or Password!" << endl;};
		void displayLock(){cout<<"Account locked after 3 consecutive fails!" << endl;};
		void displayMainMenu();
		void displayMenu();


		void displayAddStockMenu();
		void displayRemoveStockMenu();
		void displaySearchMenu();
		void displayUpdateStockMenu();
		void displayPrintReportMenu();
		void displayStockAlertMenu();
	
		
	private:
		StockList listOfStock;
		UserList listOfUser;	
		string key;
};


