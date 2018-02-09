// Stock.h
#include <string>
using namespace std;

class Stock {
	
	public:
		Stock();
		
	private:
		string itemID;
		string itemDescription;
		string itemCategory;
		string itemSubcategory;
		int amount; 		// price
		int quantity;
		// Date transactedDate;
		
};

Stock::Stock() {

}

