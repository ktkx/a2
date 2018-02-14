// StockList.h
#pragma once
#include "Stock.h"
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

class StockList {
	
	public:
		StockList();

		void provideStockAlerts(int);
		bool stockExists(string);
		int getIndex(string);
		Stock getStock(string);

		void search(int, vector<Stock>&);
		void sort_results(int, vector<Stock>&, bool);

		// edit
		void addStock(Stock);
		void updateStock(int, int);
		void removeStock(string);
		
	private:
		vector<Stock> stocks;

};

