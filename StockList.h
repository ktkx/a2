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
		void removeStock(string);
		
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

