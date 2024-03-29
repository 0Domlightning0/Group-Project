// 1Pr3-Group-Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Libraries
#include <iostream>
#include <fstream>

// Files / Classes to include 
#include "BankUser.h"
#include "Admin.h"
#include "Customer.h"
#include "CustomerSettings.h"



using namespace std;

int main()
{

    //Variables 

    int len = 0;
    string s;

    ofstream outfile;

    outfile.open("CustomerList.txt", std::ios_base::app);

    
    CustomerSettings Admin("Larrry", "Gono", "02/09/1783", "p", "20", 400508949);

    string p;
    cout << "Input Password: ";
    cin >> p;

    Admin.login(p);

    Customer* list = new Customer[100];


   Admin.createAccount(outfile);
    //list[1] = Admin.createAccount(outfile);

    //cout << list[0].get_firstname();

    // Changing info

    ifstream infile;

    infile.open("CustomerList.txt", std::ios_base::app);

    while (infile >> s) {
        len += 1;
    }
    cout << "len is " << len/6 << endl;










    ifstream infilechangeAccount;

    infilechangeAccount.open("CustomerList.txt", std::ios_base::app);

    

    Admin.changeAccount(infilechangeAccount, len/6);

    cout << "//////////////////////////////////////END OF TEST CODE//////////////////////////////////////" << endl;

    // Actual Code Area 
}

