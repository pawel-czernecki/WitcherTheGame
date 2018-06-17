#include "level.h"

    //      HANDLE hOut;
    //      hOut = GetStdHandle( STD_OUTPUT_HANDLE );

    //     SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE ); KOLOR CIEMNY MORSKI
    //     SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY ); KOLOR SELEDYNOWY
    //     SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY ); KOLOR ¯Ó£TY Z£OTY
    //     SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY ); KOLOR BIA£O SREBRNY
    //     SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY ); KOLOR CZERWONY
    //     SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY ); KOLOR ZIELONY PASTELOWY
    //     SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY ); KOLOR rózowy
    //     SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED); KOLOR PURPLE
    //     SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED ); KOLOR BR¥ZOWY

    //     SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );   --RESET KOLORU

void Level::WriteTitle()
{

    ChangeColor(3);
    cout<<Level::title<<endl;
    ChangeColor(0);
}

void Level::WriteDescription()
{
    ChangeColor(4);
    for(int i=0; i<=2; i++)
    {
        cout<<Level::description[i];
        cout<<endl;
    }
    ChangeColor(0);

}

void Level::WriteNotice(string notice)
{
    if(Level::isItemTook==0)
    {ChangeColor(8);
    cout<<notice<<endl;
    ChangeColor(0);}
}
void Level::WriteDescriptionOfSurroundings(string descriptionOS)
{
    ChangeColor(9);
    cout<<descriptionOS<<endl;
    ChangeColor(0);
}

int Level::ReturnID()
{
    return Level::id;
}

void Level::WriteDirections()
{
    ChangeColor(1);
    cout<<"Gdzie możesz iść: ";
    if (Level::north!=0)
        cout<<"north ";
    if (Level::east!=0)
        cout<<"east ";
    if (Level::south!=0)
        cout<<"south ";
    if (Level::west!=0)
        cout<<"west ";
    cout<<endl;
}

void LevelWithSimpleDialogs::IntroductionToDialog(string description)
{
    ChangeColor(5);
    cout<<"*"+description<<endl;
    ChangeColor(0);
}

void LevelWithSimpleDialogs::Dialog(string command, string person, string FirstOption, string SecondOption, string ThirdOption, string FirstAnswer, string SecondAnswer, string ThirdAnswer)
{
    if(command=="zagadaj-" + person)
    {
        cout<<"1) "<<FirstOption<<endl;
        cout<<"2) "<<SecondOption<<endl;
        cout<<"3) "<<ThirdOption<<endl;
        bool isChosen=true;
        while (isChosen)
        {
        isChosen=false;
        cout<<"Wybierz opcje:";
        cin>>LevelWithSimpleDialogs::ChosenOption;
        cout<<endl;
        if(LevelWithSimpleDialogs::ChosenOption==1){
            cout<<FirstAnswer<<endl;
        }
        else if (LevelWithSimpleDialogs::ChosenOption==2){
            cout<<SecondAnswer<<endl;
        }
        else if (LevelWithSimpleDialogs::ChosenOption==3)
        {
            cout<<ThirdAnswer<<endl;
        }
        else
        {
            cout<<"Nie ma takiej opcji :("<<endl;
            isChosen=true;
        }
        }
    }
}

int LevelWithSimpleDialogs::ReturnChosenOption()
{
    return LevelWithSimpleDialogs::ChosenOption;
}

void LevelWithShop::WriteItemList(string command)
{
    if(command=="sklep")
    {
    ChangeColor(4);
    if(AmountOfItem>=1)
        {
        cout<<"1. "<<Item1.ReturnName()<<" - "<<Item1.ReturnPrice()<<"$";
        if(Item1.ReturnStatysticName()!="hp")
         cout<<" - +"<<Item1.ReturnStatysticValue()<<Item1.ReturnStatysticName()<<endl;
         else
            cout<<endl;
        }
    if(AmountOfItem>=2)
        {
        cout<<"2. "<<Item2.ReturnName()<<" - "<<Item2.ReturnPrice()<<"$";
        if(Item2.ReturnStatysticName()!="hp")
         cout<<" - +"<<Item2.ReturnStatysticValue()<<Item2.ReturnStatysticName()<<endl;
         else
            cout<<endl;
        }
    if(AmountOfItem>=3)
        {
        cout<<"3. "<<Item3.ReturnName()<<" - "<<Item3.ReturnPrice()<<"$";
        if(Item3.ReturnStatysticName()!="hp")
         cout<<" - +"<<Item3.ReturnStatysticValue()<<Item3.ReturnStatysticName()<<endl;
         else
            cout<<endl;
        }
    if(AmountOfItem>=4)
    {
        cout<<"4. "<<Item4.ReturnName()<<" - "<<Item4.ReturnPrice()<<"$";
        if(Item4.ReturnStatysticName()!="hp")
         cout<<" - +"<<Item4.ReturnStatysticValue()<<Item4.ReturnStatysticName()<<endl;
         else
            cout<<endl;
    }
    if(AmountOfItem>=5)
    {
        cout<<"5. "<<Item5.ReturnName()<<" - "<<Item5.ReturnPrice()<<"$";
        if(Item5.ReturnStatysticName()!="hp")
         cout<<" - +"<<Item5.ReturnStatysticValue()<<Item5.ReturnStatysticName()<<endl;
         else
            cout<<endl;
    }
    ChangeColor(0);
}
}

Item LevelWithShop::ReturnItem1()
{
    return LevelWithShop::Item1;
}
Item LevelWithShop::ReturnItem2()
{
    return LevelWithShop::Item2;
}
Item LevelWithShop::ReturnItem3()
{
    return LevelWithShop::Item3;
}
Item LevelWithShop::ReturnItem4()
{
    return LevelWithShop::Item4;
}
Item LevelWithShop::ReturnItem5()
{
    return LevelWithShop::Item5;
}




void Level::ChangeColor(int color)
{
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    switch (color)
    {
    case 1:
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE ); //Ciemny morski
        break;
    case 2:
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY ); //seledynowy niebieski
        break;
    case 3:
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );//kolor ¿ólty z³oty
        break;
    case 4:
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY );//Srebrno bia³y
        break;
    case 5:
        SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );//Czerwony
        break;
    case 6:
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );//Zielony pastelowy
        break;
    case 7:
        SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY );//Ró¿owy
        break;
    case 8:
        SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED);//Br¹zowy
        break;
    case 9:
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED ); //KOLOR BR¥ZOWY
        break;
    default:
        SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED); //Reset
        break;
    }
}
