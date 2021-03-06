// StockList.h
#pragma warning(disable : 4996)
#pragma once
#include "Stock.h"
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime> 

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

		void search(char, vector<Stock>&);
		void sort_results(char, vector<Stock>&, bool);
		void printReport(char);

		// edit
		void addStock(Stock);
		void updateStock(string);
		void removeStock(string);

		void toFile();
		
	private:
		vector<Stock> stocks;

};

