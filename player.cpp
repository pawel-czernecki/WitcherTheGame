#include "player.h"


void Player::GetDamage(int NumberOfDamage)
{
    Player::hp=Player::hp-NumberOfDamage;
}

void Player::DrawHud()
{
    ChangeColor(2);
    cout<<"<"<<Player::hp<<"/"<<Player::maxhp<<"hp "<<Player::ad<<"ad "<<Player::coins<<"Gold'a "<< Player::exp<<"Exp>";
    ChangeColor(0);
}

bool Player::isDeath()
{
    if (Player::hp<=0) return true;
        else return false;
}

void Player::RemoveMoney()
{
    Player::coins=0;
    Player::hp=Player::maxhp/4;
}

void Player::GrabItem(Item ForGrab)
{
    ChangeColor(8);
    cout<<"Podnosisz ";
    ChangeColor(7);
    cout<<ForGrab.ReturnName();
    ChangeColor(8);
    if(ForGrab.ReturnStatysticName()=="ad")
    {
    cout<<" +"<<ForGrab.ReturnStatysticValue()<<" "<<ForGrab.ReturnStatysticName()<<endl;
    Player::ad+=ForGrab.ReturnStatysticValue();
    }
    if(ForGrab.ReturnStatysticName()=="maxhp")
    {
    cout<<" +"<<ForGrab.ReturnStatysticValue()<<" "<<ForGrab.ReturnStatysticName()<<endl;
    Player::maxhp+=ForGrab.ReturnStatysticValue();
    }
    ChangeColor(0);
}

void Player::GrabMoney(int Money)
{
    ChangeColor(8);
    cout<<"Podnosisz ";
    ChangeColor(7);
    cout<<Money<<" golda"<<endl;
    ChangeColor(0);
    Player::coins+=Money;
}

void Player::BuyItem(Item ForSell)//string WeaponName, int Price, string Statystic, int Value
{
    if(ForSell.ReturnPrice()<=Player::coins)
    {
       Player::coins-=ForSell.ReturnPrice();
        cout<<"Zakupiłeś "<<ForSell.ReturnName();
        if(ForSell.ReturnStatysticName()!="hp")
        cout<<" (+"<<ForSell.ReturnStatysticValue()<<ForSell.ReturnStatysticName()<<")";
        cout<<endl;
        if(ForSell.ReturnStatysticName()=="ad")
            Player::ad+=ForSell.ReturnStatysticValue();
        if(ForSell.ReturnStatysticName()=="maxhp")
            Player::maxhp+=ForSell.ReturnStatysticValue();
        if(ForSell.ReturnStatysticName()=="hp")
        {
            if(ForSell.ReturnStatysticValue()==1)
                Player::hp+=Player::maxhp/10;
             if(ForSell.ReturnStatysticValue()==2)
                Player::hp+=Player::maxhp/4;
            if(ForSell.ReturnStatysticValue()==3)
                Player::hp+=Player::maxhp/2;
             if(ForSell.ReturnStatysticValue()==4)
                Player::hp=Player::maxhp;
        if(Player::hp>Player::maxhp)
            Player::hp=Player::maxhp;
        }

    }
    else
        cout<<"Nie stać cię na to!"<<endl;
}

void Player::Fight(string OpponentName, int HP, int AD, int Chance)
{
    int EXP = HP+AD;

    ChangeColor(10);
    cout<<"Zatakował cię";
    ChangeColor(5);
    cout<<OpponentName;
    ChangeColor(10);
    cout<<"Atak:"<<AD<<"  Zdrowie:"<<HP<<endl;
    cout<<"Kliknij A-aby uderzyć słabo, kliknij S-aby uderzyć normalnie, kliknij D-aby uderzyć mocno"<<endl;
    srand( time( NULL ) );
    do
    {
        int liczba =( std::rand() % Chance ) + 1;
        if (liczba==1)
        {
            ChangeColor(6);
            cout<<"Zablokowałeś cios"<<endl;
        }
        if (liczba==2)
        {
            Player::hp-=2*AD;
            ChangeColor(10);
            cout<<"Zostałeś";
            ChangeColor(5);
            cout<<"ciężko raniony";
            ChangeColor(6);
            cout<<"["<<Player::hp<<"/"<<Player::maxhp<<"]"<<endl;
        }
        else
        {
            Player::hp-=2*AD;
            ChangeColor(10);
            cout<<"Zostałeś";
            ChangeColor(5);
            cout<<" raniony";
            ChangeColor(6);
            cout<<"["<<Player::hp<<"/"<<Player::maxhp<<"]"<<endl;
        }
        char znak=getch();
        if (znak=='a' || znak=='A')
        {
            HP-=Player::ad;
            ChangeColor(6);
            cout<<"Raniłeś ";
            ChangeColor(11);
            cout<<OpponentName;
            ChangeColor(5);
            cout<<"("<<HP<<")"<<endl;
        }
        if (znak=='s' || znak=='S')
        {
            liczba =( std::rand() % 2 ) + 1;
            if (liczba==1)
            {
                HP-=2*Player::ad;
                ChangeColor(6);
                cout<<"Raniłeś ";
                ChangeColor(11);
                cout<<OpponentName;
                ChangeColor(5);
                cout<<"("<<HP<<")"<<endl;
            }
            else
            {
                ChangeColor(11);
                cout<<OpponentName;
                ChangeColor(5);
                cout<<" zablokował twój cios"<<endl;
            }
        }
        if (znak=='d' || znak=='D')
        {
            liczba =( std::rand() % 3 ) + 1;
            if (liczba==1)
            {
                HP-=3*Player::ad;
                ChangeColor(6);
                cout<<"Ciężko raniłeś ";
                ChangeColor(11);
                cout<<OpponentName;
                cout<<"("<<HP<<")"<<endl;
            }
            else
            {
                ChangeColor(11);
                cout<<OpponentName;
                ChangeColor(5);
                cout<<" zablokował twój cios"<<endl;
            }
        }
    }while(HP>1&&Player::hp>1);
    if(HP<=0)
    {
        Player::exp+=EXP;
        ChangeColor(7);
        cout<<"Dostałeś "<<EXP<<" exp'a!"<<endl;
    }
    ChangeColor(0);
}
void Player::ChangeColor(int color)
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
        SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED);//purple
        break;
    case 9:
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED ); //KOLOR BR¥ZOWY
        break;
    case 10:
        SetConsoleTextAttribute( hOut, FOREGROUND_RED);//Czerwony ciemnu
        break;
    case 11:
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN );//Zielony
        break;
    case 0:
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED ); //reset
        break;
    }
}

int Player::ReturnHP()
{
    return Player::hp;
}
int Player::ReturnMaxHP()
{
    return Player::maxhp;
}
int Player::ReturnAd()
{
    return Player::ad;
}
int Player::ReturnCoins()
{
    return Player::coins;
}
int Player::ReturnExp()
{
    return Player::exp;
}
