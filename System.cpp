// System.cpp

#include "System.h"



void System::run() {
	
	readFile();

	/* // for testing
	for (vector<Stock>::iterator it = listOfStock.stocks.begin(); it != listOfStock.stocks.begin()+10; ++it) {
		(*it).displayStock();
	}*/

	displayMainMenu();
}

void System::readFile() {
	ifstream inFile;
	vector<string> unique_id;

	/*
	string data;
	string itemID, itemDescription, itemCategory, itemSubCategory, transactedDate;
	string amount, quantity, day, year;
	Date date;*/
	
    inFile.open("SampleData.txt");
    if (!inFile) {
        cerr << "Unable to open file";
        exit(1);
    }
    
	string line;
	string itemID, itemDescription, itemCategory, itemSubCategory;
	Date date;
	int amount, quantity;
	char garbage;

	while (getline(inFile, line)) {
		istringstream linestream(line);

		getline(linestream, itemID, ':');
		getline(linestream, itemDescription, ':');
		getline(linestream, itemCategory, ':');
		getline(linestream, itemSubCategory, ':');
		linestream >> amount >> garbage >> quantity >> garbage;
		
		linestream >> date.day >> garbage;
		getline(linestream, date.month, '-');
		linestream >> date.year;

		Stock s(itemID, itemDescription, itemCategory, itemSubCategory, amount, quantity, date);
		listOfStock.addStock(s);
	}
}



void System::encryptData() {
	// to do
}

void System::decryptData() {
	// to do
}

void System::displayLogin() {
	// to do
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
		cout << "4. Update stock (NOT DONE)" << endl;
		cout << "5. Print report (NOT DONE)" << endl;
		cout << "6. Stock alerts" << endl;
		cout << "7. Quit" << endl << endl;

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
		default: cout << "Incorrect option, please enter option 1 to 6" << endl;
			break;
		}

		
	} while (option != 7);
}

void System::displayAddStockMenu() {
	string itemID, itemDescription, itemCategory, itemSubCategory, month;
	int amount, quantity, day, year;
	Date date;
	cout << "Enter stock details: " << endl;
	cout << endl;

	cout << "Item ID: ";
	cin.clear();
	cin.ignore(10000, '\n');
	getline(cin, itemID);

	cout << "Item description: ";
	cin.clear();
	cin.ignore(10000, '\n');
	getline(cin, itemDescription);

	cout << "Item category: ";
	cin.clear();
	cin.ignore(10000, '\n');
	getline(cin, itemDescription);

	cout << "Item sub category: ";
	cin.clear();
	cin.ignore(10000, '\n');
	getline(cin, itemID);

	cout << "Item amount: ";
	cin >> amount;
	cout << "Item quantity";
	cin >> quantity;
	cout << "Date day: ";
	cin >> day;
	cout << "Date month: ";

	getline(cin, month);
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "Date year: ";
	cin >> year;

	date.day = day;
	date.month = month;
	date.year = year;

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
	int option = 0, quantity;
	string category;
	cout << "1. By category" << endl;
	cout << "2. By price (NOT DONE)" << endl;
	cout << "3. By quantity (NOT DONE)" << endl << endl;
	cout << "Please enter your option : ";
	cin >> option;

	switch (option)
	{
	case 1: cout << "Enter category: ";
		cin.clear();
		cin.ignore(10000, '\n');
		getline(cin, category);
		listOfStock.searchStockByCategory(category);
		break;
	case 2: cout << "Enter price range (X-Y): ";
		// to do
		break;
	case 3: cout << "Enter quantity range (X-Y): ";
		// to do
		break;
	}
	
	cout << endl;
}

void System::displayUpdateStockMenu() {

	string itemID, input;
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
		cout << "2. Item Description" << endl;
		cout << "3. Item Category" << endl;
		cout << "4. Item Sub-Category" << endl;
		cout << "5. Item Amount" << endl;
		cout << "6. Item Quantity" << endl;
		cout << "7. Item Date" << endl << endl;

		cout << "Please enter your option : ";
		cin >> option;

		switch (option)
		{
		case 1: cout << "Enter new ID: ";		// validation required
			cin.clear();
			cin.ignore(10000, '\n');
			getline(cin, input);

			listOfStock.stocks[index].setID(input);
			break;
		case 2: cout << "Enter new description: ";
			cin.clear();
			cin.ignore(10000, '\n');
			getline(cin, input);
			listOfStock.stocks[index].setDesc(input);
			break;
		case 3: cout << "Enter new category: ";
			cin.clear();
			cin.ignore(10000, '\n');
			getline(cin, input);
			listOfStock.stocks[index].setCat(input);
			break;
		case 4: cout << "Enter new sub-category: ";
			cin.clear();
			cin.ignore(10000, '\n');
			getline(cin, input);
			listOfStock.stocks[index].setSubCat(input);
			break;
		case 5: cout << "Enter new amount: ";
			cin >> int_input;
			listOfStock.stocks[index].setAmount(int_input);
			break;
		case 6: cout << "Enter new quantity: ";
			cin >> int_input;
			listOfStock.stocks[index].setQuantity(int_input);
			break;
		case 7: cout << "Enter new date: ";
				// to do
			break;
		default: cout << "Incorrect option, please enter option 1 to 7" << endl;
			break;
		}
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


