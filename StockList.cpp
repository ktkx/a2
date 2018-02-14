//StockList.cpp
#include "StockList.h"

StockList::StockList()
{
	ifstream inFile;

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
		addStock(s);
	}
}

void StockList::addStock (Stock st)
{
	stocks.push_back(st);
}

void StockList::provideStockAlerts(int amt) //amt = threshold set
{
	/*
	vector<int> num; //Vector array to store index of stock
	for (int i = 0; i < stocks.size(); i++)
	{
		if (stocks[i].get < amt)
			num.push_back(i); //If stock quantity < amt, store index of that stock into num array
	}

	if (num.size() > 0) //If there are stocks with quantity < amt,
	{
		cout << "Warning! Low stock!" << endl;

		//Display the stocks
		for (int i = 0; i < num.size(); i++)
			displayStock(num[i]);
	}
	else //If there is not any stock with quantity < amt, print message
		cout << "There is no item with quantity below " << amt << endl;*/

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

Stock StockList::getStock(string ID) {
	for (vector<Stock>::iterator it = stocks.begin(); it != stocks.end(); ++it) {
		if (strcmp(((*it).getID()).c_str(), ID.c_str()) == 0) {
			return *it;
		}
	}
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

void StockList::updateStock(int index, int option)
{
	string input;
	int int_input;
	Date new_date;
	char garbage;
	istringstream linestream(input);

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

void StockList::removeStock(string itemID)
{
	int index = 0;
	for (vector<Stock>::iterator it = stocks.begin(); it != stocks.end(); ++it, ++index) {
		if (itemID == (*it).getID()) {
			stocks.erase(it);
		}
	}
}



