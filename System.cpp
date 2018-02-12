// System.cpp

#include "System.h"


System::System() {
	// read in file
	// store in vectors?
}

/*
string itemID;
		string itemDescription;
		string itemCategory;
		string itemSubCategory;
		int amount; 		// price
		int quantity;
		Date transactedDate;
*/


void System::readFile() {
	ifstream inFile;
	string input;
	string itemID, itemDescription, itemCategory, itemSubCategory, transactedDate;
	int amount, quantity;
	Date date;
	
	vector<string> item;
	
    inFile.open("SampleData.txt");
    if (!inFile) {
        cerr << "Unable to open file";
        exit(1);
    }
    
    while (getline(inFile, input, '\n')) {
    	
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
    	getline(ss, date.day, '-');
    	getline(ss, date.month, '-');
    	getline(ss, date.year, '\n');
    	
    	Stock s (itemID, itemDescription, itemCategory, itemSubCategory, amount, quantity, date);
    	listOfStock.createNewRecord(s);
    
}

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
