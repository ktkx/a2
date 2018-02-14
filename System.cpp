// System.cpp

#include "System.h"

// for testing
/*
for (vector<Stock>::iterator it = listOfStock.stocks.begin(); it != listOfStock.stocks.begin()+10; ++it) {
(*it).displayStock();
}
*/

System::System() {
	key = "mywillmadereal";
}

void System::displayMenu() {
	int i = 0;
	do
	{
		cout << "1. Login" << endl;
		cout << "2. Quit" << endl;

		cout << "Please choose your option : ";
		cin >> i;

		switch (i)
		{

			case 1: displayLogin();
				break;
			case 2: exit(-1);
				break;
			default: cout << "Please enter the correct option!" << endl;
		}
	}while (i != 2);
}


string System::encryptData(string input) {
	while (key.size() < input.size())
		key += input;
	for (string::size_type i = 0; i < input.size(); ++i)
		input[i] ^= key[i];
	return input;
}

string System::decryptData(string input) {
	return encryptData(input);
}

void System::displayLogin() {

	int loginTry = 0;
	ifstream afile;
	string userId;
	string userPass;

	// ?_?
	//const int size = 30;
	//userId[size];
	//userPass[size];
	
	do
	{
		cout << "Enter Valid Username: ";
		cin >> userId;
		cout << endl;
		cout << "Enter Valid Password: ";
		cin >> userPass;
		
		bool valid = listOfUser.validateUser(userId, userPass);
		
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
			  listOfUser.lockAccount(userId);
		}
	}while (loginTry < 3);
}


void System::displayMainMenu() {
	int option = 0;
	do
	{
		option = 0;
		cout << "Warehouse Management Tool" << endl << endl;
		cout << "1. Add stock" << endl;
		cout << "2. Remove stock" << endl;
		cout << "3. Search stock" << endl;
		cout << "4. Update stock" << endl;
		cout << "5. Print report (NOT DONE)" << endl;
		cout << "6. Stock alerts" << endl;
		cout << "7. Log Out" << endl << endl;

		cout << "Please enter your option : ";
		cin >> option;
		
		switch (option)
		{
		case 1: displayAddStockMenu();
			break;
		case 2: displayRemoveStockMenu();
			break;
		case 3: displaySearchMenu();
			break;
		case 4: displayUpdateStockMenu();
			break;
		case 5: cout << "print stock menu";
			break;
		case 6: displayStockAlertMenu();
			break;
		case 7: cout << "Logging out..." << endl << endl;
			//sleep(1);			// ?_?
			displayMenu();
			break;
		default: cout << "Incorrect option, please enter option 1 to 6" << endl;
			break;
		}

		
	} while (option != 7);
}

void System::displayAddStockMenu() {
	string itemID, itemDescription, itemCategory, itemSubCategory, month, date_input;
	int amount, quantity, day, year;
	char garbage;
	Date date;
	
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

	istringstream linestream(date_input);

	linestream >> date.day >> garbage;
	getline(linestream, date.month, '-');
	linestream >> date.year;

	Stock s(itemID, itemDescription, itemCategory, itemSubCategory, amount, quantity, date);
	listOfStock.addStock(s);
}

void System::displayRemoveStockMenu() {
	string itemID;
	cout << "Enter Item ID: ";
	cin.clear();
	cin.ignore(10000, '\n');
	getline(cin, itemID);
	if (listOfStock.stockExists(itemID) == true) {
		listOfStock.removeStock(itemID);
	}
	else {
		cout << "Item not found!" << endl;
	}
}

void System::displaySearchMenu() {
	int option = 0, sort = 0;
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
		} while (sort != 1 && sort != 2);

		if (sort == 1)
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

void System::displayUpdateStockMenu() {

	string itemID;
	int int_input;
	cout << "Enter Item ID: ";
	cin.clear();
	cin.ignore(10000, '\n');
	getline(cin, itemID);
	if (listOfStock.stockExists(itemID) == true) {
		int option = 0, index = 0;
		index = listOfStock.getIndex(itemID);

		cout << "Select attribute to update" << endl << endl;
		cout << "1. Item ID" << endl;
		cout << "2. Item description" << endl;
		cout << "3. Item category" << endl;
		cout << "4. Item sub category" << endl;
		cout << "5. Item amount" << endl;
		cout << "6. Item quantity" << endl;
		cout << "7. Item date" << endl << endl;

		cout << "Please enter your option : ";
		cin >> option;

		listOfStock.updateStock(index, option);

	}
	else {
		cout << "Item not found!" << endl;
	}
}

void System::displayPrintReportMenu() {
	// to do
}

void System::displayStockAlertMenu() {
	int amount;
	cout << "Enter threshold amount: ";
	cin >> amount;
	listOfStock.provideStockAlerts(amount);
}


