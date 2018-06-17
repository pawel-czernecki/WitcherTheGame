#include "item.h"

Item::Item(string ItemName="Miecz", int ItemPrice=50, string ItemStatysticName="ad", int ItemStatysticValue=10, int ItemID=0, string ItemType="melee")
{
    Item::Name=ItemName;
    Item::Price=ItemPrice;
    Item::StatysticName=ItemStatysticName;
    Item::StatysticValue=ItemStatysticValue;
    Item::ID=ItemID;
    Item::Type=ItemType;
}

string Item::ReturnName()
{
    return Item::Name;
}

int Item::ReturnPrice()
{
    return Item::Price;
}

string Item::ReturnStatysticName()
{
    return Item::StatysticName;
}

int Item::ReturnStatysticValue()
{
    return Item::StatysticValue;
}

int Item::ReturnID()
{
    return Item::ID;
}
