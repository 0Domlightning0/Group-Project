#include <iostream>
#include <cstdlib>
#include <ctime>
#include "investMenu.h"

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    double totalAmount;
    cout << "Enter the total amount you would like to put into the investment account: ";
    cin >> totalAmount;
    
    investMenu menu(totalAmount);
    menu.originalInvestment();

    char choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Make Investment" << endl;
        cout << "2. Update Rates" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            menu.displayInvestmentOptions();
            break;
        case '2':
            menu.updateRates();
            cout << "Rates updated." << endl;
            menu.showReturn(); 
            break;
        case '3':
            cout << "Exiting program." << endl;
            //Actually supposed to go back to user options screen. Also, instead of updateRates case/option, implement updateRates() function here
            break;
        default:
            cerr << "Invalid choice. Please enter again." << endl;
        }
    } while (choice != '3');

    return 0;
}
