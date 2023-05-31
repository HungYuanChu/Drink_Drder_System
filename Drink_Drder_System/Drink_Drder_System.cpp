#include <iostream>
#include <vector>
#include <iomanip>
#include "DrinkItem.h"
#include "Drink_Drder_System.h"

void AddNewDrink(std::vector<DrinkItem>& drinks)
{
    drinks.push_back(DrinkItem("紅茶", "中杯", 30));
    drinks.push_back(DrinkItem("紅茶", "大杯", 40));
    drinks.push_back(DrinkItem("綠茶", "中杯", 35));
    drinks.push_back(DrinkItem("綠茶", "大杯", 45));
    drinks.push_back(DrinkItem("奶茶", "中杯", 50));
    drinks.push_back(DrinkItem("奶茶", "大杯", 60));
    drinks.push_back(DrinkItem("烏龍茶", "中杯", 25));
    drinks.push_back(DrinkItem("烏龍茶", "大杯", 30));
}
void DisplayDrinkMenu(vector<DrinkItem>& drinks) {
    cout << setw(4) << "編號" << setw(10) << "飲料名稱" << setw(10) << "大小" << setw(10) << "售價" << endl;
    cout << "--------------------------------------" << endl;

    /*int i = 1;
    for (DrinkItem item : drinks) {
        cout << setw(4) << i;
        item.displayItem();
        i++;
    }*/

    int i = 1;
    vector<DrinkItem>::iterator v = drinks.begin();
    while (v != drinks.end()) {
        cout << setw(4) << i;
        v->displayItem();
        v++;
        i++;
    }
    {

    }
    cout << "--------------------------------------" << endl;
}
int main()
{
    vector<DrinkItem> drinks;
    AddNewDrink(drinks);
    DisplayDrinkMenu(drinks);
}