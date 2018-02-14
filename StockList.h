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
		
		string encryptData(string);
		string decryptData(string);

		void provideStockAlerts(int);
		bool stockExists(string);
		int getIndex(string);
		vector<Stock> findAll(string);

		void search(int, vector<Stock>&);
		void sort_results(int, vector<Stock>&, bool);
		//void printReport(int);

		// edit
		void addStock(Stock);
		void updateStock(string);
		void removeStock(string);

		void toFile();
		
	private:
		vector<Stock> stocks;
		//string key = "mywillmadereal";

};

