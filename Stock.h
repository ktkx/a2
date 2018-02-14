// Stock.h
#pragma once
#include <string>
#include <iostream>
using namespace std;

struct Date
{
	int day;
	string month;
	int year;
};

class Stock {
	
	public:
		Stock();
		Stock(string, string, string, string, int, int, Date);

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

		void displayStock();
		static string dateToString(Date);
		static int monthToInt(string);
		//sort
		static bool compareDescription(Stock&, Stock&);
		static bool compareQuantity( Stock&,  Stock&);
		static bool comparePrice( Stock&,  Stock&);
		static bool compareCategory( Stock&,  Stock&);
		static bool compareSubCategory( Stock&,  Stock&);

	private:
		string itemID;
		string itemDescription;
		string itemCategory;
		string itemSubCategory;
		int amount; 		// price
		int quantity;
		Date transactedDate;
		
};

