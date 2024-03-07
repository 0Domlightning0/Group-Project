// 1Pr3-Group-Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Libraries
#include <iostream>

// Files / Classes to include 
#include "BankUser.h"


using namespace std;

int main()
{
    // Testing Area
    BankUser User("Dominik", "Wrobelski", "06/03/2024", "Password123");

    cout << User.get_firstname() << endl;

    User.set_firstname("Dominikski");

    cout << User.get_firstname();
    




    // Actual Code Area 
}

