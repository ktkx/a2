// StockList.h
#include "Stock.h"
#include <vector>
#include <algorithm>
using namespace std;

class StockList {
	
	public:
		StockList();
		void createNewRecord(string, string, string, string, int, int, Date);
		void displayStock();
		void provideStockAlerts();
		void searchStock();
		void updateStock();
		void removeStock(string);
		
		/*
		void printWhateverReport() x 4
		*/
		
		void sortPriceAscending();
		
		void sortQuantityAscending();
		
		void sortCategoryAscending();

		void sortSubCategoryAscending();
		
		
		void sortPriceDescending();
		void sortQuantityDescending();
		void sortCategoryDescending();
		void sortSubCategoryDescending();
		
		
	private:
		vector<Stock> stocks;
};

