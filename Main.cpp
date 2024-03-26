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
    ofstream outfile;

    outfile.open("CustomerAccounts");

    // Testing Area
    BankUser User("Dominik", "Wrobelski", "06/03/2024", "Password123", "20");

    cout << User.get_firstname() << endl;

    User.set_firstname("Dominikski");

    cout << User.get_firstname() << endl;

    
    CustomerSettings Admin("Larrry", "Gono", "02/09/1783", "PassPass", "20");

    string p;
    cout << "Input Password: ";
    cin >> p;

    Admin.login(p);

    Customer* list = new Customer[100];


    list[0] = Admin.createAccount();

    cout << list[0].get_firstname();

    cout << "//////////////////////////////////////END OF TEST CODE//////////////////////////////////////" << endl;

    // Actual Code Area 
}

