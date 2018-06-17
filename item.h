#pragma once
#include <iostream>

using namespace std;

class Item
{
private:
    string Name;
    int Price;
    string Type;
    string StatysticName;
    int StatysticValue;
    int ID;
public:
    string ReturnName();
    int ReturnPrice();
    string ReturnStatysticName();
    int ReturnStatysticValue();
    int ReturnID();
    Item(string ItemName, int ItemPrice, string ItemStatysticName, int ItemStatysticValue, int ItemID, string ItemType);
};
