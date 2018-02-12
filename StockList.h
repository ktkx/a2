// StockList.h
#pragma once
#include "Stock.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class StockList {
	
	public:
		StockList();
		void createNewRecord(Stock);
		
		void provideStockAlerts(int);
		void searchStockByCategory(string);
		void searchStockByPrice(int);
		void searchStockByQuantity(int);
		void updateStock(Stock, int);
		void removeStock(string);
		
		//Sort ascending
		void sortPriceAscending();
		void sortQuantityAscending();
		void sortCategoryAscending();
		void sortSubCategoryAscending();

		//Sort descending
		void sortPriceDescending();
		void sortQuantityDescending();
		void sortCategoryDescending();
		void sortSubCategoryDescending();
		
		vector<Stock> stocks;
		
	private:
		
};

