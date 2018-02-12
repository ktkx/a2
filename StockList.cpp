//StockList.cpp
#include "StockList.h"

StockList::StockList()
{
	
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

void StockList::searchStockByCategory (string cat)
{
	for (vector<Stock>::iterator it = stocks.begin(); it != stocks.end(); ++it) {
		
		if (strcmp(((*it).getCat()).c_str(), cat.c_str()) == 0) {
			(*it).displayStock();
		}
	}
}

void  StockList::searchStockByPrice(int price)
{

}

void StockList::searchStockByQuantity(int quantity)
{
	for (vector<Stock>::iterator it = stocks.begin(); it != stocks.end(); ++it) {
		if ((*it).getQuantity() == quantity) {
			(*it).displayStock();
		}
	}
}

void StockList::updateStock(Stock st, int index)
{
	stocks[index] = st;
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

void StockList::sortPriceAscending() {
	sort(stocks.begin(), stocks.end(), Stock::comparePrice);
}

void StockList::sortQuantityAscending() {
	sort(stocks.begin(), stocks.end(), Stock::compareQuantity);
}

void StockList::sortCategoryAscending() {
	sort(stocks.begin(), stocks.end(), Stock::compareCategory);
}

void StockList::sortSubCategoryAscending() {
	sort(stocks.begin(), stocks.end(), Stock::compareSubCategory);
}

void StockList::sortPriceDescending() {
	sortPriceAscending();
	reverse(stocks.begin(), stocks.end());
}

void StockList::sortQuantityDescending() {
	sortQuantityAscending();
	reverse(stocks.begin(), stocks.end());
}
void StockList::sortCategoryDescending() {
	sortCategoryAscending();
	reverse(stocks.begin(), stocks.end());
}
void StockList::sortSubCategoryDescending() {
	sortSubCategoryAscending();
	reverse(stocks.begin(), stocks.end());
}

