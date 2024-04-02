#pragma once
#include <iostream>
#include <string>
using namespace std;

class customize {
protected:
    string firstName;
    string lastName;
    string dateOfBirth;
    string password;
    string accountID;
public:
    // Constructor to initialize the object with default values
    customize();
    customize(string fName, string lName, string dateOfBirth, string pass, string id);
    //deconstructor
    ~customize();

    // Getters
    string get_firstname() { return firstName; };
    string get_lastname() { return lastName; };
    string get_dateOfBirth() { return dateOfBirth; };
    string get_password() { return password; };
    string get_ID() { return accountID; };

    // Setters
    void setFirstName(string fi) { firstName = fi; };
    void setLastName(string la) { lastName = la; };
    void setDOB(string da) { dateOfBirth = da; };
    void setPassword(string pa) { password = pa; };
    void setID(string id) { accountID = id; };

    // Function to display all the data
    void display() {
        cout << "First Name: " << firstName << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "Password: " << password << endl;
        cout << "ID: " << accountID << endl;
    }
};
