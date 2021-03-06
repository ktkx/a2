#include "Stock.h"

Stock::Stock()
{

}


Stock::Stock(string itemID, string itemDescription, string itemCategory, string itemSubCategory, int amount, int quantity, Date transactedDate)
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

bool Stock::compareQuantity( Stock& a,  Stock& b) {
	return a.getQuantity() < b.getQuantity();
}

bool Stock::comparePrice( Stock& a,  Stock& b) {
	return a.getAmount() < b.getAmount();
}

bool Stock::compareCategory( Stock& a,  Stock& b) {
	return a.getCat() < b.getCat();
}

bool Stock::compareSubCategory( Stock& a,  Stock& b) {
	return a.getSubCat() < b.getSubCat();
}


void Stock::displayStock()
{
	cout << getID() << " : "
		<< getDesc() << " : "
		<< getCat() << " : "
		<< getSubCat() << " : "
		<< getAmount() << " : "
		<< getQuantity() << " : "
		<< dateToString(getDate())
		<< endl;
}

string Stock::dateToString(Date date) {
	return to_string(date.day) + "-" + date.month + "-" + to_string(date.year);
}
