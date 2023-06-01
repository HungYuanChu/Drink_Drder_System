#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "DrinkItem.h"
#include "OrderItem.h"

//新增飲料品項
void AddNewDrink(std::vector<DrinkItem>&);

//顯示飲料菜單
void DisplayDrinkMenu(vector<DrinkItem>&);

//點餐
void OrderDrink(vector<OrderItem>&, vector<DrinkItem>&);

//計算
void CalculateSalePrice(vector<OrderItem>&, vector<DrinkItem>& drinks);