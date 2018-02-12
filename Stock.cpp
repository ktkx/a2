#include "Stock.h"

Stock::Stock()
{

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

