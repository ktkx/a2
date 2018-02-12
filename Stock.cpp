#include "Stock.h"

Stock::Stock()
{

}
itemID;
string itemDescription;
string itemCategory;
string itemSubCategory;
int amount; 		// price
int quantity;
Date transactedDate;

Stock(string itemID, string itemDescription, string itemCategory, string itemSubCategory, int amount, int quantity, Date transactedDate)
{
	this->itemID = itemID;
	this->itemDescription = itemDescription;
	this->itemCategory = itemCategory;
	this->itemSubCategory = itemSubCategory;
	this->amount = amount;
	this->quantity = quantity;
	this->transactedDate = transactedDate;
}

//assessor
string Stock::getID()
{
	return itemID;
}

string Stock::getDesc()
{
	return itemDescription;
}
		
string Stock::getCat()
{
	return itemCategory;
}
		
string Stock::getSubCat()
{
	return itemSubCategory;
}

int Stock::getAmount()
{
	return amount;
}

int Stock::getQuantity()
{
	return quantity;
}

Date Stock::getDate()
{
	return transactedDate;
}

		
		//mutator	 
void Stock::setID(string id)
{
	itemID = id;
}

void Stock::setDesc(string desc)
{
	itemDescription = desc;
}

void Stock::setCat(string cat)
{
	itemCategory = cat;
}

void Stock::setSubCat(string subCat)
{
 itemSubCategory = subCat;
}

void Stock::setAmount(int a)
{
	amount  = a;
}

void Stock::setQuantity(int q)
{
	quantity = q;
}


void Stock::setDate(Date d)
{
	transactedDate.day = d.day;
	transactedDate.month = d.month;
	transactedDate.year = d.year;
}	 	 

bool compareQuantity(const Stock& a, const Stock& b) {
	return a.quantity < b.quantity;
}

bool comparePrice(const Stock& a, const Stock& b) {
	return a.amount < b.amount;
}

bool compareCategory(const Stock& a, const Stock& b) {
	return a.itemCategory < b.itemCategory;
}

bool compareSubCategory(const Stock& a, const Stock& b) {
	return a.itemSubCategory < b.itemSubCategory;
}
