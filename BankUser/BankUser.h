// Header for BankUser class

#pragma once

#include <iostream>

using namespace std;

// Used for both the Admin and Customer class

// Parent: none

// Children: Admin, Customer

class BankUser
{
private:
	string firstname = "";
	string lastname = "";
	string dateOfBirth = "";
	string password = "";
	string age = "";
	int ID = 0;


public:
	// Default Constructor
	BankUser();

	// Overloaded Constructor for Admin
	BankUser(string fi, string la, string da, string pa, string ag, int id);

	//Overloaded Constructor for Customer
	BankUser(string fi, string la, string da, string pa, string ag, int id, double ba, bool fl);

	// Deconstructor 
	~BankUser();


	// Getters: void get_[Variable name](){ return [Variable name];};

	string get_firstname() { return firstname; };
	string get_lastname() { return lastname; };
	string get_dateOfBirth() { return dateOfBirth; };
	string get_password() { return password; };
	string get_age() { return age; };
	int get_ID() { return ID; };



	// Setters set_[Variable name](datatype [First 2 letters of variable]){ [Variable name] = [First 2 letters of variable];};

	void set_firstname(string fi) { firstname = fi; };
	void set_lastname(string la) { lastname = la; };
	void set_dateOfBirth(string da) { dateOfBirth = da; };
	void set_password(string pa) { password = pa; };
	void set_age(string ag) { age = ag; };
	void set_ID(int id) { ID = id; };


    



	// Functions:

	// Login function that uses the password and returns a bool that signals if the user(Admin/Customer) is given acccess
	virtual bool login(string p);

	// Logout function that brings the user ack to the menu
	virtual void logout();



};

