#include <iostream>
#include <fstream>
#include <string> 

#include "UserList.h"

using namespace std;

void displayMainMenu();
void displayLogin();

int main ()
{
	displayLogin();	   
}

void displayMainMenu()
{
	int option = 0;
	do
	{
	cout << "Warehouse Management Tool" << endl << endl;
	cout << "1. Add stock" << endl;
	cout << "2. Remove stock" << endl;
	cout << "3. Search stock" << endl;
	cout << "4. Update stock" << endl;
	cout << "5. Print report" << endl; 
	cout << "6. Quit" << endl << endl;
	
	cout << "Please enter your option : ";
	cin >> option;
	
	switch(option)
	{
		case 1: cout << "1";
			break;
		case 2: cout << "2";
			break;
		case 3: cout << "3";
			break;
		case 4: cout << "4";
			break;
		case 5: cout << "5";
			break;
		case 6: cout << "6";
			break;
		case 7: break;
		default: cout << "Incorrect option, please enter option 1 to 6" << endl;
			break;	    
	}
	
	}while(option != 7);
}

void displayLogin() 
{

	string userId;
	string userPass;
	int loginTry = 0;
	ifstream afile;
	const int size = 30;
	userId[size];
	userPass[size];
	
	UserList ul; 
	do
	{
		cout << "Enter Valid Username: ";
		cin >> userId;
		cout << endl;
		cout << "Enter Valid Password: ";
		cin >> userPass;
		
		bool valid = ul.validateUser(userId, userPass);
		
		if (valid == true)
		{
			displayMainMenu();
		}
		
		else 
		{
			displayFail();
			loginTry++;
		}
		
		if (loginTry == 3)
		{
			  displayLock();
			  ul.lockAccount(userId);
		}
	}while (loginTry < 3);
}

