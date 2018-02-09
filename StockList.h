// StockList.h
#include "Stock.h"

class StockList {
	
	public:
		StockList();
		void createNewRecord();
		void manageStock();
		void displayStock();
		void provideStockAlerts();
		
		/*
		void addStock();
		void searchStock();
		void updateStock();
		void removeStock();*/
		
		/*
		void printWhateverReport() x 4
		*/
		
		/*
		void sortWhatever() * 4
		*/
		
	private:
		vector<Stock> stocks;
};
