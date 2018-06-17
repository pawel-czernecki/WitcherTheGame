#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "item.h"

using namespace std;

class Level
{
private:
    int id;
    string title;
    string description[3];

protected:
    void ChangeColor(int color);
public:
    int north, east, south, west;
    bool isItemTook;
    void Move(string Text);
    void WriteTitle();
    void WriteDescription();
    void WriteDirections();
    void WriteNotice(string notice);
    void WriteDescriptionOfSurroundings(string descriptionOS);
    int ReturnID();

public:
    Level(int ID, string NameLevel, string DescriptionLine1, string DescriptionLine2, string DescriptionLine3, int North, int East, int South, int West)
    {
        north=North;
        east=East;
        south=South;
        west=West;
        title=NameLevel;
        description[0]=DescriptionLine1;
        description[1]=DescriptionLine2;
        description[2]=DescriptionLine3;
        id=ID;
        isItemTook=0;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class LevelWithSimpleDialogs :public Level
{
public:
    void IntroductionToDialog(string description);
    int ReturnChosenOption();
    void Dialog(string command, string person, string FirstOption, string SecondOption, string ThirdOption, string FirstAnswer, string SecondAnswer, string ThirdAnswer);
private:
    int ChosenOption;
public:
    LevelWithSimpleDialogs(int ID, string NameLevel, string DescriptionLine1, string DescriptionLine2, string DescriptionLine3, int North, int East, int South, int West):Level(ID, NameLevel, DescriptionLine1,DescriptionLine2,DescriptionLine3, North, East, South, West){}
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class LevelWithShop :public Level
{
private:
    int AmountOfItem;
    Item Item1;
    Item Item2;
    Item Item3;
    Item Item4;
    Item Item5;

public:
    void WriteItemList(string command);
    Item ReturnItem1();
    Item ReturnItem2();
    Item ReturnItem3();
    Item ReturnItem4();
    Item ReturnItem5();





    LevelWithShop(int ID, string NameLevel, string DescriptionLine1, string DescriptionLine2, string DescriptionLine3, int North, int East, int South, int West, Item it1, Item it2, Item it3, Item it4, Item it5, int AOI):Level(ID, NameLevel, DescriptionLine1,DescriptionLine2,DescriptionLine3, North, East, South, West),Item1(it1),Item2(it2),Item3(it3),Item4(it4),Item5(it5),AmountOfItem(AOI){}

    /*void CreateShop(int Amount, Item ItemS1(), Item ItemS2(), Item ItemS3(), Item ItemS4(), Item ItemS5())
{
    AmountOfItem=Amount;
    Item1()=ItemS1();
    Item2()=ItemS2();
    Item3()=ItemS3();
    Item4()=ItemS4();
    Item5()=ItemS5();
}*/
};
