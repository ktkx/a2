// System.h
#pragma once

#include "StockList.h"
//#include "UserList.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

class System {
	
	public:
		void readFile();
		void encryptData();
		void decryptData();

		void displayLogin();
		void displayFail(){cout<<"Invalid Username or Password!" << endl;};
		void displayMainMenu();
		


		void displayAddStockMenu();
		void displayRemoveStockMenu();
		void displaySearchMenu();
		void displayUpdateStockMenu();
		void displayPrintReportMenu();
		void displayStockAlertMenu();
		
		void run();
		
	private:
		StockList listOfStock;
		//UserList listOfUser;	
};


