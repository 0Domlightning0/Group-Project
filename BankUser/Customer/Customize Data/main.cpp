#include <iostream>
#include <string>
#include "customize.h"

using namespace std; 

int main() {
    customize userAccount;

    string firstName, lastName, dob, password, id;
    int choice = 0;

    while (choice != 6) {
        cout << "What would you like to change?" << endl;
        cout << "1. First Name" << endl;
        cout << "2. Last Name" << endl;
        cout << "3. Date of Birth" << endl;
        cout << "4. Password" << endl;
        cout << "5. Account ID" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter First Name: ";
            cin >> firstName;
        }
        else if (choice == 2) {
            cout << "Enter Last Name: ";
            cin >> lastName;
        }
        else if (choice == 3) {
            cout << "Enter Date of Birth (YYYY-MM-DD): ";
            cin >> dob;
        }
        else if (choice == 4) {
            cout << "Enter Password: ";
            cin >> password;
        }
        else if (choice == 5) {
            cout << "Enter ID: ";
            cin >> id;
        }
        else if (choice == 6) {
            //go back to user options screen
        }

        // Set the user input to the account object
        userAccount.setFirstName(firstName);
        userAccount.setLastName(lastName);
        userAccount.setDOB(dob);
        userAccount.setPassword(password);
        userAccount.setID(id);

        // Display the entered data
        cout << "\nBank Account Details:\n";
        userAccount.display();
    }
}
