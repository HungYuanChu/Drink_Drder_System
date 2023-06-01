#include "Drink_Drder_System.h"

int main()
{
    vector<DrinkItem> drinks;
    vector<OrderItem> order;

    //新增飲料品項
    AddNewDrink(drinks);

    //顯示所有的飲料菜單
    DisplayDrinkMenu(drinks);

    //點餐
    OrderDrink(order, drinks);

    //計算總額
    CalculateSalePrice(order, drinks);
}

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

void OrderDrink(vector<OrderItem>& order, vector<DrinkItem>& drinks) {
    int index;
    int qty;
    char ans = 'Y';
    do {
        cout << "請輸入要訂購的飲料編號: ";
        cin >> index;
        
        cout << "請輸入要訂購的數量: ";
        cin >> qty;
        
        if (index < 1 || index>drinks.size()) {
            cout << "編號輸入錯誤，請重新輸入" << endl;
        }
        else if (qty < 1) {
            cout << "數量輸入錯誤，請重新輸入" << endl;
        }
        else {
            OrderItem orderitem(index, qty);
            order.push_back(orderitem);
            orderitem.displayOrderItem(drinks);
            cout << "是否繼續點餐? (Y或y鍵繼續訂餐)";
            cin >> ans;
        }

    } while (ans == 'Y' || ans == 'y');
}

void CalculateSalePrice(vector<OrderItem>& order, vector<DrinkItem>& drinks) {
    int takeIN = 1;
    cout << "請問是內用還是外帶? (1:內用 2:外帶)";
    cin >> takeIN;
    string messageTakeIn = (takeIN == 1) ? "內用" : "外帶";

    int totalPrice = 0;
    int salePrice = 0;
    string messagePrice = "";
    cout << "--------------------------------------" << endl;
    cout << "您所點的飲料如下: " << endl;
    cout << "--------------------------------------" << endl;

    for (OrderItem orderitem : order) {
        orderitem.displayOrderItem(drinks);
        DrinkItem drinkitem = drinks[orderitem.getIndex() - 1];
        totalPrice += drinkitem.getPrice() * orderitem.getQuantity();
    }
    
    if (totalPrice >= 500) {
        salePrice = totalPrice * 0.8;
        messagePrice = "訂購500元以上者8折";
    }
    else if (totalPrice >= 300) {
        salePrice = totalPrice * 0.9;
        messagePrice = "訂購300元以上者9折";
    }
    else if (totalPrice >= 200) {
        salePrice = totalPrice * 0.95;
        messagePrice = "訂購200元以上者95折";
    }
    else {
        salePrice = totalPrice;
        messagePrice = "訂購未滿200元不打折";
    }

    cout << "--------------------------------------" << endl;
    cout << "訂購方式: " << messageTakeIn << endl;
    cout << "總金額: " << totalPrice << endl;
    cout << messagePrice << endl;
    cout << "售價: " << salePrice << endl;
    cout << "--------------------------------------" << endl;

}