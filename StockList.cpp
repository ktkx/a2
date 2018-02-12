//StockList.cpp
#include "StockList.h"

StockList::StockList()
{
	
}

void StockList::createNewRecord (Stock st)
{
	stocks.push_back(st);
}

/*
void StockList::provideStockAlerts(int amt) //amt = threshold set
{
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
		cout << "There is no item with quantity below " << amt << endl;
}


void StockList::searchStockByCategory (string cat)
{
	for (int i = 0; i < stocks.size(); i++)
	{
		if (cat == stocks[i].getCat())
			displayStock(i);
	}
}

void StockList::searchStockByPrice(int price)
{
	for (int i = 0; i < stocks.size(); i++)
	{
		if (price == stocks[i].getAmount())
			displayStock(i);
	}
}

void StockList::searchStockByQuantity(int quantity)
{
	for (int i = 0; i < stocks.size(); i++)
	{
		if (quantity == stocks[i].getQuantity())
			displayStock(i);
	}
}*/

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

