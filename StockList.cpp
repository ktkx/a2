//StockList.cpp
#include "StockList.h"


StockList::StockList()
{

}
void StockList::createNewRecord(string itemID, string itemDescription, string itemCategory, string itemSubCategory, int amount, int quantity, Date transactedDate)
{
	Stock s (itemID, itemDescription, string itemCategory, itemSubCategory, amount, quantity, transactedDate);
	stocks.push_back(s);
}

void StockList::displayStock()
{

}
void StockList::provideStockAlerts()


}

void StockList::addStock()
{

}
void StockList::searchStock()
{

}
void StockList::updateStock()
{

}
void StockList::removeStock(string itemID)
{
	int index = 0;
	 for (vector<int>::iterator it = stocks.begin() ; it != stocks.end(); ++it, ++index) {
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

void sortCategoryAscending()  {
	sort(stocks.begin(), stocks.end(), Stocks::compareCategory);
}

void sortSubCategoryAscending() {
	sort(stocks.begin(), stocks.end(), Stocks::compareSubCategory);
}

void sortPriceDescending() {
	sortPriceAscending();
	reverse(stocks.begin(),stocks.end());
}

void sortQuantityDescending() {
	sortQuantityAscending();
	reverse(stocks.begin(),stocks.end());
}
void sortCategoryDescending() {
	sortCategoryAscending();
	reverse(stocks.begin(),stocks.end());
}
void sortSubCategoryDescending() {
	sortSubCategoryAscending();
	reverse(stocks.begin(),stocks.end());
}

