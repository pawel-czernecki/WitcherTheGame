#include  <iostream>
#include <cstdlib>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include "item.h"

using namespace std;

class Player
{
private:
    int hp;
    int maxhp;
    int ad;
    int coins;
    int exp;
    void ChangeColor(int color);
public:
    void RemoveMoney();
    void GetDamage(int NumberOfDamage);//Zadawanie damagu graczowi
    void DrawHud();//Hud z statami
    bool isDeath();//Zwraca czy gracz jest martwy
    void GrabItem(Item ForGrab);//Podniesienie przedmiotu przez gracza
    void BuyItem(Item ForSell);//Kupowanie przedmiotów --- Przy dodawaniu hp 1-10% 2-25% 3-50% 4-100%
    void GrabMoney(int Money);
    void Fight(string OpponentName, int HP, int AD, int Chance);// Szansa na krytykala do jakiejœ tam liczby  1 to blok 2 to krytykalń
    int ReturnHP();
    int ReturnMaxHP();
    int ReturnAd();
    int ReturnCoins();
    int ReturnExp();
    Player(int HealthPoints, int MaxHealthPoints, int AtackDamage, int Money, int Exp)
    {
        hp=HealthPoints;
        maxhp=MaxHealthPoints;
        ad=AtackDamage;
        coins = Money;
        exp=Exp;
    }
};
