#pragma once
#include "investments.h"
#include "TFSA.h"
#include "GIC.h"
#include "stocks.h"
class investMenu :  public investments {
protected:
    double totalAmount = 0;
    double tfsaOriginal = 0;
    double gicOriginal = 0;
    double stocksOriginal = 0;
    double tfsaAdd = 0, gicAdd = 0, stocksAdd = 0;
    double tfsaNew = 0, gicNew = 0, stocksNew = 0;
    TFSA tfsaOption;
    GIC gicOption;
    stocks stocksOption;

public:
    investMenu();
    investMenu(double amount);
    ~investMenu();

    void originalInvestment() {

        cout << "Enter amount for TFSA: ";
        cin >> tfsaOriginal;

        cout << "Enter amount for GIC: ";
        cin >> gicOriginal;

        cout << "Enter amount for Stocks: ";
        cin >> stocksOriginal;

        if (tfsaOriginal + gicOriginal + stocksOriginal > totalAmount) {
            cerr << "Total investment amount exceeds available funds." << endl;
            tfsaOriginal = 0;
            gicOriginal = 0;
            stocksOriginal = 0;
            return;
        }

        cout << "TFSA return: " << tfsaOption.calculateReturn(tfsaOriginal) << endl;
        cout << "GIC return: " << gicOption.calculateReturn(gicOriginal) << endl;
        cout << "Stocks return: " << stocksOption.calculateReturn(stocksOriginal) << endl;
    }

    void displayInvestmentOptions() {

        cout << "Enter amount for TFSA: ";
        cin >> tfsaAdd;
        tfsaNew = tfsaOriginal + tfsaAdd;

        cout << "Enter amount for GIC: ";
        cin >> gicAdd;
        gicNew = gicOriginal + gicAdd;

        cout << "Enter amount for Stocks: ";
        cin >> stocksAdd;
        stocksNew = stocksOriginal + stocksAdd;

        if (tfsaNew + gicNew + stocksNew > totalAmount) {
            cerr << "Total investment amount exceeds available funds." << endl;
            tfsaNew = tfsaOriginal;
            gicNew = gicOriginal;
            stocksNew = stocksOriginal;
            return;
        }

        cout << "TFSA return: " << tfsaOption.calculateReturn(tfsaNew) << endl;
        cout << "GIC return: " << gicOption.calculateReturn(gicNew) << endl;
        cout << "Stocks return: " << stocksOption.calculateReturn(stocksNew) << endl;
    }

    void showReturn() {
        if (tfsaAdd == 0 or (tfsaNew + gicNew + stocksNew > totalAmount)) {
            cout << "TFSA return: " << tfsaOption.calculateReturn(tfsaOriginal) << endl;
        }
        else {
            cout << "TFSA return: " << tfsaOption.calculateReturn(tfsaNew) << endl;
        }
        if (gicAdd == 0 or (tfsaNew + gicNew + stocksNew > totalAmount)) {
            cout << "GIC return: " << gicOption.calculateReturn(gicOriginal) << endl;
        }
        else {
            cout << "GIC return: " << gicOption.calculateReturn(gicNew) << endl;
        }
        if (stocksAdd == 0 or (tfsaNew + gicNew + stocksNew > totalAmount)) {
            cout << "Stocks return: " << stocksOption.calculateReturn(stocksOriginal) << endl;
        }
        else {
            cout << "Stocks return: " << stocksOption.calculateReturn(stocksNew) << endl;
        }
    }

    void updateRates() {
        tfsaOption.updateRate();
        gicOption.updateRate();
        stocksOption.updateRate();
    }
};
