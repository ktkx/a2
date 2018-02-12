// System.cpp

#include "System.h"



void System::run() {
	
	readFile();
	for (vector<Stock>::iterator it = listOfStock.stocks.begin(); it != listOfStock.stocks.end(); ++it) {
		(*it).displayStock();
	}

	cout << "sxdzd";
}



void System::readFile() {
	ifstream inFile;
	string data;
	string itemID, itemDescription, itemCategory, itemSubCategory, transactedDate;
	string amount, quantity, day, year;
	Date date;
	
	vector<string> item;
	
    inFile.open("SampleData.txt");
    if (!inFile) {
        cerr << "Unable to open file";
        exit(1);
    }
    
    while (getline(inFile, data, '\n')) {
    	
    	/*
    	char* token;
    	token = strtok (data,":");
    	while (token != NULL)
		{
			item.push_back(token)
			pch = strtok (NULL, ":");
		}
		
		for (vector<string>::iterator it = item.begin() ; it != item.begin+4; ++it) {
			
    	}*/
    	
    	istringstream ss(data);
    	
    	getline(ss, itemID, ':');
    	getline(ss, itemDescription, ':');
    	getline(ss, itemCategory, ':');
    	getline(ss, itemSubCategory, ':');
    	
    	getline(ss, amount, ':');
    	getline(ss, quantity, ':');
    	
    	// date stuff
    	getline(ss, day, '-');
    	getline(ss, date.month, '-');
    	getline(ss, year, '\n');

		date.day = atoi(day.c_str());
		date.year =atoi(year.c_str());
		

    	
    	Stock s (itemID, itemDescription, itemCategory, itemSubCategory, atoi(amount.c_str()),atoi(quantity.c_str()), date);
    	listOfStock.createNewRecord(s);
    
	}

}


	/*
void System::encryptData() {
	
}

void System::decryptData() {
	
}

void System::displayLogin() {
	
}
void System::displayFail(){cout<<"Invalid Username or Password!" << endl;};

int System::displayMainMenu() {
	
}

void System::displayEditDetails() {
	
}
*/



