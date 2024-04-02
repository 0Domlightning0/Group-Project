#include "investMenu.h"

investMenu::investMenu() {
    totalAmount = 0;
    tfsaOriginal = 0;
    gicOriginal = 0;
    stocksOriginal = 0;
    tfsaAdd = 0;
    gicAdd = 0;
    stocksAdd = 0;
    tfsaNew = 0;
    gicNew = 0;
    stocksNew = 0;
}
investMenu::investMenu(double amount) {
    totalAmount = amount;
}
investMenu::~investMenu() {

}
