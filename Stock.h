// Stock.h
#include <string>
using namespace std;

struct Date
{
	int day;
	int month;
	int year;
};

class Stock {
	
	public:
		Stock();
		
		//assessor
		
		//mutator	 
		void setID(string);
		void setDesc(string);
		void setCat(string);
		void setSubCat(string);
		void setAmount(int);
		void setQuantity(int);
		void setDate(Date);	   	   
		
	private:
		string itemID;
		string itemDescription;
		string itemCategory;
		string itemSubcategory;
		int amount; 		// price
		int quantity;
		Date transactedDate;
		
};


Stock::Stock() {

}

