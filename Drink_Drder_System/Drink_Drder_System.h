#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "DrinkItem.h"
#include "OrderItem.h"

//�s�W���ƫ~��
void AddNewDrink(std::vector<DrinkItem>&);

//��ܶ��Ƶ��
void DisplayDrinkMenu(vector<DrinkItem>&);

//�I�\
void OrderDrink(vector<OrderItem>&, vector<DrinkItem>&);

//�p��
void CalculateSalePrice(vector<OrderItem>&, vector<DrinkItem>& drinks);