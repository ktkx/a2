//StockList.cpp
#include "StockList.h"

StockList::StockList()
{
	
}

void StockList::createNewRecord (Stock st)
{
	stocks.push_back (&st);
}

void StockList::displayStock(int index)
{
	cout << stocks[index].getID() << " : " 
		<< stocks[index].getDesc() << " : " 
		<< stocks[index].getCat() << " : " 
		<< stocks[index].getSubCat() << " : " 
		<< stocks[index].getAmount() << " : " 
		<< stocks[index].getQuantity() << " : " 
		<< stocks[index].getDate() << endl;
}

void StockList::provideStockAlerts()
{

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
}

void StockList::updateStock(Stock st, int index)
{
	stocks[index] = &st;
}
void StockList::removeStock(string itemID)
{
	int index = 0;
	for (vector<int>::iterator it = stocks.begin(); it != stocks.end(); ++it, ++index) {
		if (itemID == *it.getID()) {
			stocks.erase(it);
		}
	}
}

void sortPriceAscending() {
	sort(stocks.begin(), stocks.end(), Stocks::comparePrice);
}

void sortQuantityAscending() {
	sort(stocks.begin(), stocks.end(), Stocks::compareQuantity);
}

void sortCategoryAscending() {
	sort(stocks.begin(), stocks.end(), Stocks::compareCategory);
}

void sortSubCategoryAscending() {
	sort(stocks.begin(), stocks.end(), Stocks::compareSubCategory);
}

void sortPriceDescending() {
	sortPriceAscending();
	reverse(stocks.begin(), stocks.end());
}

void sortQuantityDescending() {
	sortQuantityAscending();
	reverse(stocks.begin(), stocks.end());
}
void sortCategoryDescending() {
	sortCategoryAscending();
	reverse(stocks.begin(), stocks.end());
}
void sortSubCategoryDescending() {
	sortSubCategoryAscending();
	reverse(stocks.begin(), stocks.end());
}

