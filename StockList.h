// StockList.h
#include "Stock.h"
#include <vector>
using namespace std;

class StockList {
	
	public:
		StockList();
		void createNewRecord(Stock);
		void updateStock();
		void displayStock();
		void provideStockAlerts();
		void searchStock();
		void removeStock();
		
		/*
		void printWhateverReport() x 4
		*/
		
		/*
		void sortWhatever() * 4
		*/
		
	private:
		vector<Stock> stocks;
};

