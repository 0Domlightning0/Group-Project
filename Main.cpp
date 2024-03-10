// 1Pr3-Group-Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Libraries
#include <iostream>

// Files / Classes to include 
#include "BankUser.h"
#include "Admin.h"


using namespace std;

int main()
{
    // Testing Area
    BankUser User("Dominik", "Wrobelski", "06/03/2024", "Password123");

    cout << User.get_firstname() << endl;

    User.set_firstname("Dominikski");

    cout << User.get_firstname() << endl;

    
    Admin CEO("Larrry", "Gono", "02/09/1783", "PassPass");

    string p;

    cin >> p;

    CEO.login(p);

    cout << "//////////////////////////////////////END OF TEST CODE//////////////////////////////////////" << endl;

    // Actual Code Area 
}

