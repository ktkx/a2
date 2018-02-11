#include <iostream>
#include <iomanip>
#include "System.h"

using namespace std;

int displayMainMenu();
void displayLogin();

int main ()
{
	displayLogin();	   
	displayMainMenu();
}

int displayMainMenu()
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
	string id;
	string pass;
	cout << "===================" << endl;
	cout << "       Login       " << endl;
	cout << "===================" << endl;
	cout << "Enter username: " ;
	cin >> id;
	cout << "Enter password: ";
	cin >> pass;
	
}

