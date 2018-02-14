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

bool Stock::compareDescription(Stock& a, Stock& b) {
	return a.getDesc() < b.getDesc();
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

int Stock::monthToInt()
{
	string m = getDate().month;

	if (m == "Jan")
		return 1;
	else if (m == "Feb")
		return 2;
	else if (m == "Mar")
		return 3;
	else if (m == "Apr")
		return 4;
	else if (m == "May")
		return 5;
	else if (m == "Jun")
		return 6;
	else if (m == "Jul")
		return 7;
	else if (m == "Aug")
		return 8;
	else if (m == "Sep")
		return 9;
	else if (m == "Oct")
		return 10;
	else if (m == "Nov")
		return 11;
	else 
		return 12;
}

void Stock::displayReport()
{
	cout << setw(15) << left << getID();

	if (getQuantity() < 0)
	{
		cout << setw(10) << left << "0"
			<< setw(10) << left << getQuantity() * (-1);
	}
	else
	{
		cout << setw(10) << left << getQuantity()
			<< setw(10) << left << "0";
	}

	cout << setw(20) << left << getAmount();

	cout.imbue(locale(""));
	cout << setw(20) << left << getQuantity() * getAmount() * (-1) << endl;
	cout.imbue(locale(locale("C")));
}