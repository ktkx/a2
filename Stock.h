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
		string getID();
		string getDesc();
		string getCat();
		string getSubCat();
		int getAmount();
		int getQuantity();
		Date getDate();


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
		string itemSubCategory;
		int amount; 		// price
		int quantity;
		Date transactedDate;
		
};

