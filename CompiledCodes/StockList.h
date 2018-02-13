// StockList.h
#pragma once
#include "Stock.h"
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class StockList {
	
	public:
		StockList();

		void provideStockAlerts(int);
		bool stockExists(string);
		int getIndex(string);
		Stock getStock(string);

		// search
		void searchStockByCategory(string);
		void searchStockByPrice(int);
		void searchStockByQuantity(int);

		// edit
		void addStock(Stock);
		void updateStock(Stock, int);
		void removeStock(string);
		
		//Sort ascending
		void sortPriceAscending();
		void sortQuantityAscending();
		void sortCategoryAscending();
		void sortSubCategoryAscending();

		//Sort descending
		// to do - implement as separate or within search
		void sortPriceDescending();
		void sortQuantityDescending();
		void sortCategoryDescending();
		void sortSubCategoryDescending();
		
		vector<Stock> stocks;
		
	private:
		
};

