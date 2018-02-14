//StockList.cpp
#include "StockList.h"

StockList::StockList()
{
	ifstream inFile;
	bool decrypt = false;

	inFile.open("output.txt");

	if (!inFile)
	{
		inFile.open("SampleData.txt");

		if (!inFile) {
			cerr << "Unable to open file";
			exit(1);
		}
	}
	else
		decrypt = true;

	string line;
	string itemID, itemDescription, itemCategory, itemSubCategory;
	Date date;
	int amount, quantity;
	char garbage;

	while (getline(inFile, line)) {
		if (decrypt)
			line = decryptData(line);
		
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
		addStock(s);
	}
}

void StockList::addStock (Stock st)
{
	stocks.push_back(st);
}

void StockList::provideStockAlerts(int amt) //amt = threshold set
{
	int count = 0;
	for (vector<Stock>::iterator it = stocks.begin(); it != stocks.end(); ++it) {
		if ((*it).getQuantity() < amt) {
			count++;
			if (count == 1) {
				cout << "Warning! The following items are low in stock." << endl;
			}
			(*it).displayStock();	
		}
	}

	if (count == 0) {
		cout << "There is no item with quantity below " << amt << endl;
	}
}

bool StockList::stockExists(string ID) {
	for (vector<Stock>::iterator it = stocks.begin(); it != stocks.end(); ++it) {
		if (strcmp(((*it).getID()).c_str(), ID.c_str()) == 0) {
			return true;
		}
	}
	return false;
}

int StockList::getIndex(string ID) {
	int index = 0;
	for (vector<Stock>::iterator it = stocks.begin(); it != stocks.end(); ++it, ++index) {
		if (strcmp(((*it).getID()).c_str(), ID.c_str()) == 0) {
			return index;
		}
	}
}

vector<Stock> StockList::findAll(string ID) {
	vector<Stock> results;
	for (vector<Stock>::iterator it = stocks.begin(); it != stocks.end(); ++it) {
		if (strcmp(((*it).getID()).c_str(), ID.c_str()) == 0) {
			results.push_back(*it);
		}
	}
	return results;
}

void StockList::search(int option, vector<Stock>& search_results) {
	string input;
	int range1, range2;
	Date date;

	switch (option)
	{
	case 1: cout << "Enter category: ";
		cin.clear();
		cin.ignore(10000, '\n');
		getline(cin, input);

		for (vector<Stock>::iterator it = stocks.begin(); it != stocks.end(); ++it) {
			if (strcmp(((*it).getCat()).c_str(), input.c_str()) == 0) {
				//(*it).displayStock();
				search_results.push_back(*it);
			}
		}
		break;
	case 2: cout << "Enter sub category";
		cin.clear();
		cin.ignore(10000, '\n');
		getline(cin, input);

		for (vector<Stock>::iterator it = stocks.begin(); it != stocks.end(); ++it) {
			if (strcmp(((*it).getSubCat()).c_str(), input.c_str()) == 0) {
				//(*it).displayStock();
				search_results.push_back(*it);
			}
		}
		break;
	case 3: cout << "Enter price range (e.g. 10 20): ";
		cin >> range1 >> range2;
		for (vector<Stock>::iterator it = stocks.begin(); it != stocks.end(); ++it) {
			if ((*it).getAmount() >= range1 && (*it).getAmount() <= range2) {
				search_results.push_back(*it);
			}
		}
		break;

	case 4: cout << "Enter quantity range (e.g. 1000 2000): ";
		cin >> range1 >> range2;
		for (vector<Stock>::iterator it = stocks.begin(); it != stocks.end(); ++it) {
			if ((*it).getQuantity() >= range1 && (*it).getQuantity() <= range2) {
				search_results.push_back(*it);
			}
		}
		break;
	}
}

void StockList::sort_results(int option, vector<Stock>& search_results, bool ascending) {
	switch (option)
	{
	case 1: sort(search_results.begin(), search_results.end(), Stock::compareDescription);
		break;
	case 2: sort(search_results.begin(), search_results.end(), Stock::compareDescription);
		break;
	case 3: sort(search_results.begin(), search_results.end(), Stock::comparePrice);
		break;
	case 4: sort(search_results.begin(), search_results.end(), Stock::compareQuantity);
		break;
	}
	if (!ascending) {
		reverse(search_results.begin(), search_results.end());
	}
		
}

void StockList::updateStock(string ID)
{
	string input;
	int index = 0;
	int int_input, option;
	Date new_date;
	char garbage;
	istringstream linestream(input);

	cout << "Displaying all matching records: " << endl;
	for (vector<Stock>::iterator it = stocks.begin(); it != stocks.end(); ++it, index++) {
		if (strcmp(((*it).getID()).c_str(), ID.c_str()) == 0) {
			cout << "[Record " << index << "] ";
			(*it).displayStock();
		}
	}
	cout << endl;
	cout << "Select a record to update: ";
	cin >> index;

	cout << "\nSelect attribute to update" << endl << endl;
	cout << "1. Item ID" << endl;
	cout << "2. Item description" << endl;
	cout << "3. Item category" << endl;
	cout << "4. Item sub category" << endl;
	cout << "5. Item amount" << endl;
	cout << "6. Item quantity" << endl;
	cout << "7. Item date" << endl << endl;

	cout << "Please enter your option : ";
	cin >> option;

	switch (option)
	{
	case 1: cout << "Enter new ID: ";		// validation required
		cin.clear();
		cin.ignore(10000, '\n');
		getline(cin, input);
		stocks[index].setID(input);
		break;

	case 2: cout << "Enter new description: ";
		cin.clear();
		cin.ignore(10000, '\n');
		getline(cin, input);
		stocks[index].setDesc(input);
		break;

	case 3: cout << "Enter new category: ";
		cin.clear();
		cin.ignore(10000, '\n');
		getline(cin, input);
		stocks[index].setCat(input);
		break;

	case 4: cout << "Enter new sub category: ";
		cin.clear();
		cin.ignore(10000, '\n');
		getline(cin, input);
		stocks[index].setSubCat(input);
		break;

	case 5: cout << "Enter new amount: ";
		cin >> int_input;
		stocks[index].setAmount(int_input);
		break;

	case 6: cout << "Enter new quantity: ";
		cin >> int_input;
		stocks[index].setQuantity(int_input);
		break;

	case 7: cout << "Enter new date(DD-Mmm-YY): ";
		cin.clear();
		cin.ignore(10000, '\n');
		getline(cin, input);

		linestream >> new_date.day >> garbage;
		getline(linestream, new_date.month , '-');
		linestream >> new_date.year;

		stocks[index].setDate(new_date);

		break;

	default: cout << "Incorrect option, please enter option 1 to 7" << endl;
		break;
	}
}

void StockList::removeStock(string ID)
{
	int index = 0, option = 0;
	
	cout << "Displaying all matching records: " << endl;
	for (vector<Stock>::iterator it = stocks.begin(); it != stocks.end(); ++it, index++) {
		if (strcmp(((*it).getID()).c_str(), ID.c_str()) == 0) {
			cout << "[Record " << index << "] ";
			(*it).displayStock();
		}
	}
	cout << endl;
	cout << "Select a record to delete: ";
	cin >> option;

	stocks.erase(stocks.begin() + option);
	cout << endl;
	cout << "Record " << option << " successfully deleted!" << endl;

	/*

	for (vector<Stock>::iterator it = stocks.begin(); it != stocks.end(); ++it, ++index) {
		if (itemID == (*it).getID()) {
			stocks.erase(it);
		}
	}*/
}

void StockList::toFile() {
	ofstream outFile;
	outFile.open("output.txt");
	string line;
	 
	for (vector<Stock>::iterator it = stocks.begin(); it != stocks.end(); ++it) {
		line = (*it).getID() + ":" + (*it).getDesc() + ":" + (*it).getCat() + ":" + (*it).getSubCat() + ":"
			+ to_string((*it).getAmount()) + ":" + to_string((*it).getQuantity()) + ":"
			+ (*it).dateToString((*it).getDate());
		
		line = encryptData(line);

		outFile << line << '\n';

		/*
		outFile << encryptData((*it).getID()) << ":"
			<< encryptData((*it).getDesc()) << ":"
			<< encryptData((*it).getCat()) << ":"
			<< encryptData((*it).getSubCat()) << ":"
			<< encryptData(to_string((*it).getAmount())) << ":"
			<< encryptData(to_string((*it).getQuantity())) << ":"
			<< encryptData((*it).dateToString((*it).getDate()))
			<< "\n";*/
	}
	outFile.close();
}

string StockList::encryptData(string toEncrypt) {
	/*while (key.size() < input.size())
		key += input;
	for (int i = 0; i < input.size(); ++i)
		input[i] ^= key[i];
	return input;*/

	string output = toEncrypt;

	for (int i = 0; i < toEncrypt.size(); i++)
		output[i] = toEncrypt[i] + 4;

	return output;
}

string StockList::decryptData(string toDecrypt) {
	string output = toDecrypt;

	for (int i = 0; i < toDecrypt.size(); i++)
		output[i] = toDecrypt[i] - 4;

	return output;
}

void StockList::printReport(int option)
{
	time_t rawtime = time(NULL);
	struct tm * timeinfo = localtime(&rawtime);

	int day = timeinfo->tm_mday;
	int month = timeinfo->tm_mon + 1;
	int year = timeinfo->tm_year + 1900;

	year = 2014;

	switch (option)
	{
	case 1:
		for (vector<Stock>::iterator it = stocks.begin(); it != stocks.end(); ++it)
		{
			if ((year == (*it).getDate().year + 2000 && month == (*it).monthToInt()) && day == (*it).getDate().day)
				(*it).displayReport();
		}
		break;
	case 2:
		for (vector<Stock>::iterator it = stocks.begin(); it != stocks.end(); ++it)
		{
			if ((year == (*it).getDate().year + 2000 && month == (*it).monthToInt() && day - 7 <= (*it).getDate().day && day >= (*it).getDate().day) ||
				(year == (*it).getDate().year + 2000 && month-1 == (*it).monthToInt() && day+23 <= (*it).getDate().day && day <= 7) ||
				(year-1 == (*it).getDate().year + 2000 && month+11 == (*it).monthToInt() && day+23 <= (*it).getDate().day && day <= 7 && month <= 1))
				(*it).displayReport();
		}
		break;
	case 3:
		for (vector<Stock>::iterator it = stocks.begin(); it != stocks.end(); ++it)
		{
			if ((year == (*it).getDate().year + 2000 && month == (*it).monthToInt() && day >= (*it).getDate().day) ||
				(year == (*it).getDate().year + 2000 && month-1 == (*it).monthToInt() && day <= (*it).getDate().day) ||
				(year - 1 == (*it).getDate().year + 2000 && month+11 <= (*it).monthToInt() && day <= (*it).getDate().day) && month <=1)
				(*it).displayReport();
		}
		break;
	case 4:
		for (vector<Stock>::iterator it = stocks.begin(); it != stocks.end(); ++it)
		{
			if (year == (*it).getDate().year + 2000 || (year - 1 == (*it).getDate().year + 2000 && month <= (*it).monthToInt()))
				(*it).displayReport();
		}
		break;
	}
}