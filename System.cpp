// System.cpp

#include "System.h"

System::System() {
	
}

void System::displayMenu() {
	char i;
	//Loop menu until user enters 3
	do
	{
		cout << "1. Login" << endl;
		cout << "2. Handle Locked Account" << endl;
		cout << "3. Quit" << endl;

		cout << "Please choose your option : ";
		cin >> i;
		cout << endl;

		switch (i)
		{

		case '1': displayLogin(); //Login option
			break;
		case '2': handleLockedAccount(); //Handle Locked Account
			break;
		case '3': exit(-1); //Quit
			break;
		default: cout << "Please enter the correct option!" << endl; //If not entered 1, 2 or 3

		}
	} while (i != '3');
	cout << endl;
}

void System::displayLogin() {
	string userId;
	string userPass;
	int loginTry = 0;
	ifstream afile;
	
	//Loop until user login successfully OR user fails to login 3 times
	do
	{
		cout << "Enter Valid Username: ";
		cin >> userId;
		cout << endl;
		cout << "Enter Valid Password: ";
		cin >> userPass;

		if (checkLockedAccount(userId) == false)
		{
			bool valid = listOfUser.validateUser(userId, userPass); //Validate account information
			//If login successful, show main menu
			if (valid == true)
			{
				displayMainMenu();
			}
			else //If unsuccessful, increase loginTry by 1
			{
				cout << endl;
				displayFail();
				cout << endl;
				loginTry++;
			}
			//If user failed login 3 times,
			if (loginTry == 3)
			{
				displayLock();
				lockAccount(userId); //Lock account
			}
		}//if checkLockAcc
		else
		{
			cout << "Account '" << userId << "' has been locked! " << endl;
			cout << "Please Go to Option 2 (Handle Locked Account) to unlock you account " << endl;
			cout << endl;
			break;
		}
	} while (loginTry < 3);
}

bool System::checkLockedAccount(string u)
{

	for (int i = 0; i < lockedAccount.size(); i++)
	{
		if (u == lockedAccount[i])
			return true;
	}
	return false;

}


void System::lockAccount(string id)
{
	lockedAccount.push_back(id);
}

void System::unlockAccount(string id)
{
	for (int i = 0; i < lockedAccount.size(); i++)
	{
		if (id == lockedAccount[i])
		{
			cout << "Account '" << lockedAccount[i] << "' successfully unlocked " << endl;
			lockedAccount.pop_back();
			break;
		}
	}
}


void System::handleLockedAccount()
{
	string userId, reason;
	cout << "Enter Locked Username: ";
	cin >> userId;
	cout << endl;
	unlockAccount(userId);
}


void System::displayMainMenu() {
	char option;
	//Loop menu until user enters 7 (quit)
	do
	{
		option = '0';
		cout << endl;
		cout << "Warehouse Management Tool" << endl << endl;
		cout << "1. Add stock" << endl;
		cout << "2. Remove stock" << endl;
		cout << "3. Search stock" << endl;
		cout << "4. Update stock" << endl;
		cout << "5. Print report" << endl;
		cout << "6. Stock alerts" << endl;
		cout << "7. Log Out" << endl << endl;

		cout << "Please enter your option : ";
		cin >> option;
		
		switch (option)
		{
		case '1': displayAddStockMenu();
			break;
		case '2': displayRemoveStockMenu();
			break;
		case '3': displaySearchMenu();
			break;
		case '4': displayUpdateStockMenu();
			break;
		case '5': displayPrintReportMenu();
			break;
		case '6': displayStockAlertMenu();
			break;
		case '7': cout << "Logging out..." << endl << endl;
			listOfStock.toFile(); //Encrypt stock records
			displayMenu(); //Back to login menu
			break;
		default: cout << "Incorrect option, please enter option 1 to 7" << endl;
			break;
		}

		
	} while (option != 7);
}

//Add new stock
void System::displayAddStockMenu() {
	string itemID, itemDescription, itemCategory, itemSubCategory, month, date_input;
	int amount, quantity, day, year;
	char garbage;
	Date date;

	//Get stock details from user
	cout << "Enter stock details: " << endl;
	cout << endl;
	
	cout << "Item ID: ";
	cin >> itemID;

	cout << "Item description: ";
	cin.clear();
	cin.ignore(10000, '\n');
	getline(cin, itemDescription);

	cout << "Item category: ";
	getline(cin, itemCategory);

	cout << "Item sub category: ";
	getline(cin, itemSubCategory);

	cout << "Item amount: ";
	cin >> amount;
	cout << "Item quantity: ";
	cin >> quantity;

	cout << "Enter new date(DD-Mmm-YY): ";
	cin.clear();
	cin.ignore(10000, '\n');
	getline(cin, date_input);

	//Put string date_input into Date structure
	istringstream linestream(date_input);

	linestream >> date.day >> garbage;
	getline(linestream, date.month, '-');
	linestream >> date.year;

	//Add new stock
	Stock s(itemID, itemDescription, itemCategory, itemSubCategory, amount, quantity, date);
	listOfStock.addStock(s);

	cout << "New stock succesfully added!" << endl;
}

//Remove stock
void System::displayRemoveStockMenu() {
	string itemID;
	int option, count = 1;
	//Get stock ID
	cout << "Enter Item ID: ";
	cin.clear();
	cin.ignore(10000, '\n');
	getline(cin, itemID);

	//Find stock to remove
	if (listOfStock.stockExists(itemID) == true) {
		listOfStock.removeStock(itemID); //Remove stock
	}
	else {
		cout << "Item not found!" << endl; //If stock does not exist, print message
	}
}

//Search stock
void System::displaySearchMenu() {
	char option = '0', sort = '0';
	bool ascending;
	string category;
	vector<Stock> search_results;

	// get search option
	cout << "1. By category" << endl;
	cout << "2. By sub category" << endl;
	cout << "3. By price" << endl;
	cout << "4. By quantity" << endl << endl;
	cout << "Please enter your option : ";
	cin >> option;

	listOfStock.search(option, search_results);
	cout << endl;

	// if there are matching results
	if (!search_results.empty()) {
		// get sort option
		do {
			cout << "Sort results by: " << endl;
			cout << "1. Ascending" << endl;
			cout << "2. Descending" << endl << endl;
			cout << "Please enter your option : ";
			cin >> sort;
		} while (sort != '1' && sort != '2');

		if (sort == '1')
			ascending = true;
		else
			ascending = false;

		listOfStock.sort_results(option, search_results, ascending);

		// print out each stock in accordance with user specifications
		for (vector<Stock>::iterator it = search_results.begin(); it != search_results.end(); ++it) {
			(*it).displayStock();
		}
	}

	else {
		cout << "No records found!" << endl;
	}
	
	cout << endl;
}

//Update stock
void System::displayUpdateStockMenu() {

	string itemID;
	int int_input;
	//Get stock ID to update
	cout << "Enter Item ID: ";
	cin.clear();
	cin.ignore(10000, '\n');
	getline(cin, itemID);

	//if the stock exists,
	if (listOfStock.stockExists(itemID) == true) {
		int option = 0, index = 0;
		index = listOfStock.getIndex(itemID);
		listOfStock.updateStock(itemID); //Update stock information

		cout << endl << "Stock updated" << endl << endl;
	}
	else {
		cout << "Item not found!" << endl; //If does not exist, print message
	}
}

//Print report
void System::displayPrintReportMenu() {
	char option;
	//Print stock menu
	cout << "1. Daily stock summary report" << endl
		<< "2. Weekly stock summary report" << endl
		<< "3. Monthly stock summary report" << endl
		<< "4. Yearly stock summary report" << endl << endl;

	cout << "Select report type: ";
	cin >> option;

	listOfStock.printReport(option); //Print report
}

//Stock alert
void System::displayStockAlertMenu() {
	int amount;

	//Get threshold amount
	cout << "Enter threshold amount: ";
	cin >> amount;
	listOfStock.provideStockAlerts(amount); //Provide alert
}


