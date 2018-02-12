// StockList.h
#include "Stock.h"
#include <vector>
using namespace std;

class StockList {
	
	public:
		StockList();
		void createNewRecord(Stock);
		void displayStock();
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
		
	private:
		vector<Stock> stocks;
};

