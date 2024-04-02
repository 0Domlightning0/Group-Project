#include "customize.h"

customize::customize() {
    firstName = "";
    lastName = "";
    dateOfBirth = "";
    password = "";
    accountID = "";
}
customize::customize(string fName, string lName, string dob, string pass, string id) {
    firstName = fName;
    lastName = lName;
    dateOfBirth = dob;
    password = pass;
    accountID = id;
}
customize::~customize() {

}
