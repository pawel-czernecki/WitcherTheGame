#include "level.h"
#include "gamesystem.h"
#include "player.h"
#include "menu.h"
#include "item.h"

using namespace std;

GameSystem Game;

int main()
{
    //Tworzenie objektów broni
    Item Nothing("ERROR 404 ;)", 99999999, "-", 0, 0, "-");

    Item StalowyMiecz("Stalowy miecz", 50, "ad", 5, 1, "melee");
    Item TemerskiMiecz("Temerski miecz", 100, "ad", 11, 2, "melee");
    Item NilfgardzkiMiecz("Nilfgardzki miecz", 150, "ad", 16, 3, "melee");
    Item Ementaler("Ementaler", 225, "ad", 23, 4, "melee");
    Item SrebrnyMWCKota("Srebrny miecz wiedzminskiego cechu kota", 265, "ad", 27, 5, "melee");
    Item WysmienityMieczWCW("Wysmienity miecz wiedzminskiego cechu wilka", 390, "ad", 40, 6, "melee");
    Item Zerwikaptur("Zerwikaptur", 550, "ad", 56, 7, "melee");
    Item DumaPolnocy("Duma Północy", 900, "ad", 100, 8, "melee");

    Item ZbrojaWCW("Zbroja Wiedźmińskiego Cechu Wilka", 50, "maxhp", 5, 1, "armor");
    Item NilfgardzkaZbroja("Nilfgardzka Zbroja", 100, "maxhp", 11, 2, "armor");
    Item KeadwanskaZbroja("Keadwanska Zbroja", 210, "maxhp", 23, 3, "armor");
    Item ZbrojaKrolestwPolnocy("Zbroja Krolestw Polnocy", 320, "maxhp", 33, 4, "armor");
    Item UlepszonaZbrojaWCM("Ulepszona Zbroja Wiedźmińskiego Cechu Mantikory", 500, "maxhp", 51, 5, "armor");
    Item UlepszonaZbrojaWCK("Ulepszona Zbroja Wiedźmińskiego Cechu Kota", 700, "maxhp", 76, 6, "armor");
    Item UlepszonaZbrojaWCW("Ulepszona Zbroja Wiedźmińskiego Cechu Wilka", 900, "maxhp", 100, 7, "armor");
    Item ArcymistrzowskaZbrojaWCW("Arcymistrzowska Zbroja Wiedźmińskiego Cechu Wilka", 1600, "maxhp", 200, 8, "armor");

    Item Bandarz("Bandarz", 5, "hp", 1, 1, "heal");
    Item MalaApteczka("Mala Apteczka", 10, "hp", 2, 2, "heal");
    Item DuzaApteczka("Duza Apteczka", 20, "hp", 3, 3, "heal");
    Item Jaskolka("Mikstura Jaskolka", 50, "hp", 4, 4, "heal");


    //
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    ////////////////////////////////////////////////////////////////////////////////
    Menu MainMenu(1, "Witcher the Game v0.1", "Start", "Jak grac", "Creditsy", "Wyjdz");
    MainMenu.drawmenu();
    string text;
    if (MainMenu.nmenu()==1)
   {
       if (Game.ReadFile(1)==0){
        ////////Tworzenie postaci///////////////////
       /* system("cls"); //STARE TWORZENIE POSTACI
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY );
        cout<<"Wybierz typ bohatera:"<<endl;
        cout<<"*Szermierz"<<endl;
        cout<<"*Bogacz"<<endl;
        cout<<"*Czolg"<<endl;
        cout<<"*Przecietniak"<<endl;
        cout<<endl;
        bool isSelect=true;
        for(int i=0; isSelect==true; i++)
        {
        cout<<"Wpisz typ bohatera: ";
        string PlayerType;
        cin>>PlayerType;
        cout<<endl;
        isSelect=false;
        if ( i==2)
        {
            cout<<"Skoro, nie umiesz tego wpisać, wybrałem ci Przecietniaka :)"<<endl;
            PlayerType="Przecietniak";
            Sleep(2000);
            isSelect=false;
        }
        ///////Tworzenie objektu player/////////////////
        if (PlayerType=="Szermierz") {
            Player Geralt(25, 25, 50, 100, 0);
            Game.SaveFile(1, 25, 25, 50, 100, 0, 1);
            cout<<"Wybrales Szermierza!"<<endl;
            cout<<"Twoją główną zaletą jest fechtunek. Twoje ciosy"<<endl;
            cout<<"są zawsze bezbłędne. Jednak jak to wiedźmin"<<endl;
            cout<<"groszem nie śmierdzisz."<<endl;

        }
        else if (PlayerType=="Bogacz") {
            Player Geralt(20, 20, 25, 500,0);
            Game.SaveFile(1, 20, 20, 25, 500, 0, 1);
            cout<<"Wybrales Bogacza!"<<endl;
            cout<<"Jesteś jednym z najbogatszych wiedźminów, jednak nie wskazują"<<endl;
            cout<<" na to twoje umiejętności. Krążą plotki, że dorobiłeś się na hazardzie"<<endl;
            cout<<"lub innych szemranych interesach."<<endl;
        }
        else if (PlayerType=="Czolg") {
            Player Geralt(50, 50, 25, 100, 0);
            Game.SaveFile(1, 50, 50, 25, 100, 0, 1);
            cout<<"Wybrales Czołg!"<<endl;
            cout<<"Podczas próby traw niezwykle rozwinęła się u ciebie"<<endl;
            cout<<"wytrzymałość na obrażenia. Jednak jak to wiedźmin"<<endl;
            cout<<"groszem nie śmierdzisz."<<endl;
        }
        else if (PlayerType=="Przecietniak") {
            Player Geralt(30, 30, 30, 250, 0);
            Game.SaveFile(1, 30, 30, 30, 250, 0, 1);
            cout<<"Wybrales Przeciętniaka!"<<endl;
            cout<<"Niczym się nie wyróżniasz."<<endl;
            cout<<"Posiadasz małe oszczędności."<<endl;

        }
        else isSelect=true;*/
        Menu CharacterChoice(0, "Wybierz klase bohatera:","Szermierz", "Czołg", "Bogacz", "Przeciętniak" );
        CharacterChoice.drawmenu();
        if(CharacterChoice.nmenu()==1)//Szermierz
        {
            Player Geralt(25, 25, 50, 100, 0);
            Game.SaveFile(1, 25, 25, 50, 100, 0, 1);
            cout<<"Wybrales Szermierza!"<<endl;
            cout<<"Twoją główną zaletą jest fechtunek. Twoje ciosy"<<endl;
            cout<<"są zawsze bezbłędne. Jednak jak to wiedźmin"<<endl;
            cout<<"groszem nie śmierdzisz."<<endl;
        }
        if(CharacterChoice.nmenu()==2)//Czołg
           {
            Player Geralt(50, 50, 25, 100, 0);
            Game.SaveFile(1, 50, 50, 25, 100, 0, 1);
            cout<<"Wybrales Czołg!"<<endl;
            cout<<"Podczas próby traw niezwykle rozwinęła się u ciebie"<<endl;
            cout<<"wytrzymałość na obrażenia. Jednak jak to wiedźmin"<<endl;
            cout<<"groszem nie śmierdzisz."<<endl;
           }
        if(CharacterChoice.nmenu()==3)//Bogacz
            {
            Player Geralt(20, 20, 25, 500,0);
            Game.SaveFile(1, 20, 20, 25, 500, 0, 1);
            cout<<"Wybrales Bogacza!"<<endl;
            cout<<"Jesteś jednym z najbogatszych wiedźminów, jednak nie wskazują"<<endl;
            cout<<" na to twoje umiejętności. Krążą plotki, że dorobiłeś się na hazardzie"<<endl;
            cout<<"lub innych szemranych interesach."<<endl;
            }
        if(CharacterChoice.nmenu()==4)//Przeciętniak
        {
            Player Geralt(30, 30, 30, 250, 0);
            Game.SaveFile(1, 30, 30, 30, 250, 0, 1);
            cout<<"Wybrales Przeciętniaka!"<<endl;
            cout<<"Niczym się nie wyróżniasz."<<endl;
            cout<<"Posiadasz małe oszczędności."<<endl;
        }
        cout<<endl;cout<<"Wciśnij dowolny klawisz, aby kontynuować..."<<endl;getch();system("cls");
        cout<<"\"Później mówiono, ";
            Sleep(1000);
            cout<<"że człowiek ów nadszedł od północy, "<<endl;
            Sleep(1000);
            cout<<"od Bramy Powroźniczej. ";
            Sleep(1000);
            cout<<"Nie był stary, ";
            Sleep(1000);
            cout<<"ale włosy miał zupełnie białe. "<<endl;
            Sleep(1000);
            cout<<"Kiedy ściągnął płaszcz okazało się,";
            Sleep(1000);
             cout<<"że na pasie za plecami ma miecz.\'"<<endl;
             cout<<"~~Andrzej Sapkowski, Ostatnie życzenie";
        cout<<endl;cout<<"Wciśnij dowolny klawisz, aby kontynuować..."<<endl;getch();}system("cls");
       Player Geralt(Game.ReadFile(2), Game.ReadFile(3), Game.ReadFile(4), Game.ReadFile(5), Game.ReadFile(6));
       Game.ChangeCurrentID(Game.ReadFile(7));
        /////////////KONIEC TWORZENIA BOHATERA
        while (true)
        {
            Game.SaveFile(1, Geralt.ReturnHP(), Geralt.ReturnMaxHP(), Geralt.ReturnAd(), Geralt.ReturnCoins(), Geralt.ReturnExp(), Game.ReturnCurrentID());
            Game.LevelEnd=0;
            //End Screen
            if (Game.ReturnCurrentID()==0)
            {
                cout<<"Straciłeś przytomność, nieznajomy zaniósł cię do miasta, ale ograbił cię z całych oszczędności."<<endl;
                Game.ChangeCurrentID(1);
                Geralt.RemoveMoney();
            }
            //BRAMA POŁUGNIOWA
            LevelWithSimpleDialogs BramaPoludniowa(1, "Brama Południowa", "Stoisz przed wielką podniesiąną żelazną", "bramą. Z boku w kolejce do urzędnika stoi", "tłum krzykliwych ludzi.", 2, 0, 0, 0);
            if(Game.ReturnCurrentID()==BramaPoludniowa.ReturnID())
            {
                BramaPoludniowa.WriteTitle();
                BramaPoludniowa.WriteDirections();
                BramaPoludniowa.WriteDescription();
                BramaPoludniowa.IntroductionToDialog("Jeden ze strażków dziwnie się na ciebie patrzy.");
                BramaPoludniowa.WriteDescriptionOfSurroundings("Napisz \"zagadaj-straznik\", aby porozmawiać z strażnikiem.");
                Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, BramaPoludniowa.north, BramaPoludniowa.east, BramaPoludniowa.south, BramaPoludniowa.west);
                BramaPoludniowa.Dialog( text , "straznik", "Co robią tutaj ci ludzie?", "Co to za miasto?", "Znajdzie się tutaj dla mnie jakieś zlecenie?", "Kupcy... chcą zapłacić cło za towary", "Brugge, najpiękniejsze miasto pomiędzy Jarugą, Wstążką i Travą.", "Tyś pan wiedźmin, podobno Venzlav szuka posła do dziwożon. Znajdziesz go w swoim pałacu.");

                }
                continue;
            }

            //Ul. POŁUDNIOWA
            Level Poludniowa1( 2 , "Ul. Południowa 5", "Stoisz na niezbyt szerokiej brudnej", "drodze, która rozciąga się wzdłuż", "muru.", 66, 64, 1, 3);
            if(Game.ReturnCurrentID()==Poludniowa1.ReturnID())
            {
                Poludniowa1.WriteTitle();
                Poludniowa1.WriteDirections();
                Poludniowa1.WriteDescription();
                Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Poludniowa1.north, Poludniowa1.east, Poludniowa1.south, Poludniowa1.west);
            }
            continue;
        }
        //Poludniowa2
         Level Poludniowa2( 3 , "Ul. Południowa 4", "Stoisz na niezbyt szerokiej brudnej", "drodze, która rozciąga się wzdłuż", "muru.", 0, 2, 0, 4);
            if(Game.ReturnCurrentID()==Poludniowa2.ReturnID())
            {
                Poludniowa2.WriteTitle();
                Poludniowa2.WriteDirections();
                Poludniowa2.WriteDescription();
                Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Poludniowa2.north, Poludniowa2.east, Poludniowa2.south, Poludniowa2.west);
            }
            continue;
        }

        //Poludniowa3
         Level Poludniowa3( 4 , "Ul. Południowa 3", "Stoisz na niezbyt szerokiej brudnej", "drodze, która rozciąga się wzdłuż", "muru.", 5, 3, 0, 6);
            if(Game.ReturnCurrentID()==Poludniowa3.ReturnID())
            {
                Poludniowa3.WriteTitle();
                Poludniowa3.WriteDirections();
                Poludniowa3.WriteDescription();
                Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Poludniowa3.north, Poludniowa3.east, Poludniowa3.south, Poludniowa3.west);
            }
            continue;
        }
        //KOWAL 1
        LevelWithShop Kowal1( 5 , "Kowal", "Stoisz koło umieśnionego kowala. Po twojej lewej", "stronie znajduje się kowadło oraz piec hutniczy,", "a po prawej stoją stojaki z mieczami.", 0, 0, 4, 0, TemerskiMiecz, NilfgardzkiMiecz, Ementaler, SrebrnyMWCKota, WysmienityMieczWCW, 5);
            if(Game.ReturnCurrentID()==Kowal1.ReturnID())
            {
                Kowal1.WriteTitle();
                Kowal1.WriteDirections();
                Kowal1.WriteDescription();
                Kowal1.WriteDescriptionOfSurroundings("Napisz \"sklep\", aby wyświetlić listę przedmiotów do kupna.");
                Kowal1.WriteDescriptionOfSurroundings("Napisz \"kup-(numer przedmiotu z listy)\", aby kupić dany przedmiot.");
                Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Kowal1.WriteItemList(text);
                Game.Move(text, Kowal1.north, Kowal1.east, Kowal1.south, Kowal1.west);
                if(text=="kup-1")
                    Geralt.BuyItem(Kowal1.ReturnItem1());
                if(text=="kup-2")
                    Geralt.BuyItem(Kowal1.ReturnItem2());
                if(text=="kup-3")
                    Geralt.BuyItem(Kowal1.ReturnItem3());
                if(text=="kup-4")
                    Geralt.BuyItem(Kowal1.ReturnItem4());
                if(text=="kup-5")
                    Geralt.BuyItem(Kowal1.ReturnItem5());

            }
            continue;
        }
        //Poludniowa4
         Level Poludniowa4( 6 , "Ul. Południowa 2", "Stoisz na niezbyt szerokiej brudnej", "drodze, która rozciąga się wzdłuż", "muru.", 0, 4, 0, 7);
            if(Game.ReturnCurrentID()==Poludniowa4.ReturnID())
            {
                Poludniowa4.WriteTitle();
                Poludniowa4.WriteDirections();
                Poludniowa4.WriteDescription();
                Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Poludniowa4.north, Poludniowa4.east, Poludniowa4.south, Poludniowa4.west);
            }
            continue;
        }
       //Poludniowa5
         Level Poludniowa5( 7 , "Ul. Południowa 1", "Stoisz na niezbyt szerokiej brudnej", "drodze, która rozciąga się wzdłuż", "muru.", 8, 6, 0, 0);
            if(Game.ReturnCurrentID()==Poludniowa5.ReturnID())
            {
                Poludniowa5.WriteTitle();
                Poludniowa5.WriteDirections();
                Poludniowa5.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Poludniowa5.north, Poludniowa5.east, Poludniowa5.south, Poludniowa5.west);
            }
            continue;
        }

        //Leśna1
        Level Lesna1(8, "Ul. Leśna 1", "Stoisz na wąskiej dróżce. W pobliżu ", "płynie strumyk, w którym wesoło", "pływają ryby", 9, 0, 7, 14);
        if(Game.ReturnCurrentID()==Lesna1.ReturnID())
            {
                Lesna1.WriteTitle();
                Lesna1.WriteDirections();
                Lesna1.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Lesna1.north, Lesna1.east, Lesna1.south, Lesna1.west);
            }
            continue;
        }
        //Leśna2
        Level Lesna2(9, "Ul. Leśna 2", "Stoisz na wąskiej dróżce. W pobliżu ", "płynie strumyk, w którym wesoło", "pływają ryby", 10, 0, 8, 0);
        if(Game.ReturnCurrentID()==Lesna2.ReturnID())
            {
                Lesna2.WriteTitle();
                Lesna2.WriteDirections();
                Lesna2.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Lesna2.north, Lesna2.east, Lesna2.south, Lesna2.west);
            }
            continue;
        }

        //Leśna3
        Level Lesna3(10, "Ul. Leśna 3", "Stoisz na wąskiej dróżce. W pobliżu ", "płynie strumyk, w którym wesoło", "pływają ryby", 0, 0, 9, 11);
        if(Game.ReturnCurrentID()==Lesna3.ReturnID())
            {
                Lesna3.WriteTitle();
                Lesna3.WriteDirections();
                Lesna3.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Lesna3.north, Lesna3.east, Lesna3.south, Lesna3.west);
            }
            continue;
        }
        //Leśna4
        Level Lesna4(11, "Ul. Leśna 4", "Stoisz na wąskiej dróżce. W pobliżu ", "płynie strumyk, w którym wesoło", "pływają ryby", 0, 10, 0, 12);
        if(Game.ReturnCurrentID()==Lesna4.ReturnID())
            {
                Lesna4.WriteTitle();
                Lesna4.WriteDirections();
                Lesna4.WriteDescription();
                cout<<Lesna4.south<<endl;
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Lesna4.north, Lesna4.east, Lesna4.south, Lesna4.west);
            }
            continue;
        }
        //Leśna5
        Level Lesna5(12, "Ul. Leśna 5", "Stoisz na wąskiej dróżce. W pobliżu ", "płynie strumyk, w którym wesoło", "pływają ryby", 0, 11, 13, 20);
        if(Game.ReturnCurrentID()==Lesna5.ReturnID())
            {
                Lesna5.WriteTitle();
                Lesna5.WriteDirections();
                Lesna5.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Lesna5.north, Lesna5.east, Lesna5.south, Lesna5.west);
            }
            continue;
        }

        //Leśna6
        Level Lesna6(13, "Ul. Leśna 6", "Stoisz na wąskiej dróżce. W pobliżu ", "płynie strumyk, w którym wesoło", "pływają ryby", 12, 0, 19, 0);
        if(Game.ReturnCurrentID()==Lesna6.ReturnID())
            {
                Lesna6.WriteTitle();
                Lesna6.WriteDirections();
                Lesna6.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Lesna6.north, Lesna6.east, Lesna6.south, Lesna6.west);
            }
            continue;
        }

        //Leśna7
        Level Lesna7(14, "Ul. Leśna", "Stoisz na wąskiej dróżce. W pobliżu ", "płynie strumyk, w którym wesoło", "pływają ryby", 0, 8, 0, 19);
        if(Game.ReturnCurrentID()==Lesna7.ReturnID())
            {
                Lesna7.WriteTitle();
                Lesna7.WriteDirections();
                Lesna7.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Lesna7.north, Lesna7.east, Lesna7.south, Lesna7.west);
            }
            continue;
        }
        //Las1
        Level Las1(15, "Las", "Stoisz pośrodku wielkiego skupiska", "drzew. Przez niektóre korony przebijają się", "wiązki światła.", 0, 19, 17, 0);
        if(Game.ReturnCurrentID()==Las1.ReturnID())
            {
                Las1.WriteTitle();
                Las1.WriteDirections();
                Las1.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Las1.north, Las1.east, Las1.south, Las1.west);
            }
            continue;
        }
        //Las2;
        Level Las2(16, "Las", "Stoisz pośrodku wielkiego skupiska", "drzew. Przez niektóre korony przebijają się", "wiązki światła.", 0, 17, 0, 0);
        if(Game.ReturnCurrentID()==Las2.ReturnID())
            {
                Las2.WriteTitle();
                Las2.WriteDirections();
                Las2.WriteDescription();
                Geralt.Fight("Leszy", 150, 5, 3);
                Game.LevelEnd=0;
                if (Geralt.isDeath())
                    {
                        Game.ChangeCurrentID(0);
                        Game.LevelEnd=1;
                    }
                else
                    Geralt.GrabMoney(200);
                while (Game.LevelEnd==0)
                {

                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Las2.north, Las2.east, Las2.south, Las2.west);
            }
            continue;
            }

        //Las3
        Level Las3(17, "Las", "Stoisz pośrodku wielkiego skupiska", "drzew. Przez niektóre korony przebijają się", "wiązki światła.", 15, 18, 0, 16);
        if(Game.ReturnCurrentID()==Las3.ReturnID())
            {
                Las3.WriteTitle();
                Las3.WriteDirections();
                Las3.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Las3.north, Las3.east, Las3.south, Las3.west);
            }
            continue;
        }
        //Polana1
        Level Polana1(18, "Polana", "Stoisz na wielkiej polanie", "wyścielonej dywanami wysokich traw.", "W oddali widać las.", 19, 0, 0, 17);
        if(Game.ReturnCurrentID()==Polana1.ReturnID())
            {
                Polana1.WriteTitle();
                Polana1.WriteDirections();
                Polana1.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Polana1.north, Polana1.east, Polana1.south, Polana1.west);
            }
            continue;
        }
        //Polana2
        Level Polana2(19, "Polana", "Stoisz pośrodku wielkiego skupiska", "drzew. Przez niektóre korony przebijają się", "wiązki światła.", 13, 14, 18, 15);
        if(Game.ReturnCurrentID()==Polana2.ReturnID())
            {
                Polana2.WriteTitle();
                Polana2.WriteDirections();
                Polana2.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Polana2.north, Polana2.east, Polana2.south, Polana2.west);
            }
            continue;
        }
        //Cmentarna1
        Level Cmentarna1(20, "Ul. Cmentarna", "Stoisz na starej, brudnej drodze. Większość", "domów wokoło wydaje się opuszczonych. W oddali ", "słyszysz odgłosy ghuli i wampir ekimmy lub katakana.", 21, 12, 0, 0);
        if(Game.ReturnCurrentID()==Cmentarna1.ReturnID())
            {
                Cmentarna1.WriteTitle();
                Cmentarna1.WriteDirections();
                Cmentarna1.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Cmentarna1.north, Cmentarna1.east, Cmentarna1.south, Cmentarna1.west);
            }
            continue;
        }

        //Cmentarna2
        Level Cmentarna2(21, "Ul. Cmentarna", "Stoisz na starej, brudnej drodze. Większość", "domów wokoło wydaje się opuszczonych. W oddali ", "słyszysz odgłosy ghuli i wampir ekimmy lub katakana.", 22, 0, 20, 100);
        if(Game.ReturnCurrentID()==Cmentarna2.ReturnID())
            {
                Cmentarna2.WriteTitle();
                Cmentarna2.WriteDirections();
                Cmentarna2.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Cmentarna2.north, Cmentarna2.east, Cmentarna2.south, Cmentarna2.west);
            }
            continue;
        }
        //Cmentarna3
        Level Cmentarna3(22, "Ul. Cmentarna", "Stoisz na starej, brudnej drodze. Większość", "domów wokoło wydaje się opuszczonych. W oddali ", "słyszysz odgłosy ghuli i wampir ekimmy lub katakana.", 24, 23, 21, 0);
        if(Game.ReturnCurrentID()==Cmentarna3.ReturnID())
            {
                Cmentarna3.WriteTitle();
                Cmentarna3.WriteDirections();
                Cmentarna3.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Cmentarna3.north, Cmentarna3.east, Cmentarna3.south, Cmentarna3.west);
            }
            continue;
        }
        //APTEKA1
        LevelWithShop Apteka1( 23 , "Apteka", "Stoisz przed ladą, za którą stoi", "zielarz. Wokół unosi się zapach różnorodnych", "ziół. Na półkach leżą ususzone zioła.", 0, 0, 0, 22, Bandarz, MalaApteczka, DuzaApteczka, Jaskolka, Nothing, 4);
            if(Game.ReturnCurrentID()==Apteka1.ReturnID())
            {
                Apteka1.WriteTitle();
                Apteka1.WriteDirections();
                Apteka1.WriteDescription();
                Apteka1.WriteDescriptionOfSurroundings("Napisz \"sklep\", aby wyświetlić listę przedmiotów do kupna.");
                Apteka1.WriteDescriptionOfSurroundings("Napisz \"kup-(numer przedmiotu z listy)\", aby kupić dany przedmiot.");
                Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Apteka1.WriteItemList(text);
                Game.Move(text, Apteka1.north, Apteka1.east, Apteka1.south, Apteka1.west);
                if(text=="kup-1")
                    Geralt.BuyItem(Apteka1.ReturnItem1());
                if(text=="kup-2")
                    Geralt.BuyItem(Apteka1.ReturnItem2());
                if(text=="kup-3")
                    Geralt.BuyItem(Apteka1.ReturnItem3());
                if(text=="kup-4")
                    Geralt.BuyItem(Apteka1.ReturnItem4());
                if(text=="kup-5")
                    Geralt.BuyItem(Apteka1.ReturnItem5());

            }
            continue;
        }
        //Cmentarna4
        Level Cmentarna4(24, "Ul. Cmentarna", "Stoisz na starej, brudnej drodze. Większość", "domów wokoło wydaje się opuszczonych. W oddali ", "słyszysz odgłosy ghuli i wampir ekimmy lub katakana.", 28, 0, 22, 25);
        if(Game.ReturnCurrentID()==Cmentarna4.ReturnID())
            {
                Cmentarna4.WriteTitle();
                Cmentarna4.WriteDirections();
                Cmentarna4.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Cmentarna4.north, Cmentarna4.east, Cmentarna4.south, Cmentarna4.west);
            }
            continue;
        }

        //Cmentarna5
        Level Cmentarna5(25, "Ul. Cmentarna", "Stoisz na starej, brudnej drodze. Większość", "domów wokoło wydaje się opuszczonych. W oddali ", "słyszysz odgłosy ghuli i wampir ekimmy lub katakana.", 0, 24, 0, 26);
        if(Game.ReturnCurrentID()==Cmentarna5.ReturnID())
            {
                Cmentarna5.WriteTitle();
                Cmentarna5.WriteDirections();
                Cmentarna5.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Cmentarna5.north, Cmentarna5.east, Cmentarna5.south, Cmentarna5.west);
            }
            continue;
        }
        //Cmentarna6
        Level Cmentarna6(28, "Ul. Cmentarna", "Stoisz na starej, brudnej drodze. Większość", "domów wokoło wydaje się opuszczonych. W oddali ", "słyszysz odgłosy ghuli i wampir ekimmy lub katakana.", 29, 0, 24, 0);
        if(Game.ReturnCurrentID()==Cmentarna6.ReturnID())
            {
                Cmentarna6.WriteTitle();
                Cmentarna6.WriteDirections();
                Cmentarna6.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Cmentarna6.north, Cmentarna6.east, Cmentarna6.south, Cmentarna6.west);
            }
            continue;
        }
        //Cmentarna7
        Level Cmentarna7(29, "Ul. Cmentarna", "Stoisz na starej, brudnej drodze. Większość", "domów wokoło wydaje się opuszczonych. W oddali ", "słyszysz odgłosy ghuli i wampir ekimmy lub katakana.", 0, 30, 28, 0);
        if(Game.ReturnCurrentID()==Cmentarna7.ReturnID())
            {
                Cmentarna7.WriteTitle();
                Cmentarna7.WriteDirections();
                Cmentarna7.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Cmentarna7.north, Cmentarna7.east, Cmentarna7.south, Cmentarna7.west);
            }
            continue;
        }
        //Cmentarz
        Level Cmentarz(26, "Cmentarz", "Stoisz na placu pełnym zamszonych", " grobów. Kilka ghuli rozkopuje mogiłe", "lub je zgnite ludzkie mięso.", 0, 25, 27, 0);
        if(Game.ReturnCurrentID()==Cmentarz.ReturnID())
            {
                Cmentarz.WriteTitle();
                Cmentarz.WriteDirections();
                Cmentarz.WriteDescription();
                 Geralt.Fight("Grupa ghuli", 100, 25, 10);
                Game.LevelEnd=0;
                if (Geralt.isDeath())
                    {
                        Game.ChangeCurrentID(0);
                        Game.LevelEnd=1;
                    }
                else
                    Geralt.GrabMoney(150);
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Cmentarz.north, Cmentarz.east, Cmentarz.south, Cmentarz.west);
            }
            continue;
        }
        //Kaplica
        Level Kaplica(27, "Kaplica", "Stoisz w małej kaplicy. Ławki", " są połamane. Na ołtarzu ", "leży porwany obrus.", 26, 0, 0, 0);
        if(Game.ReturnCurrentID()==Kaplica.ReturnID())
            {
                Kaplica.WriteTitle();
                Kaplica.WriteDirections();
                Kaplica.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Kaplica.north, Kaplica.east, Kaplica.south, Kaplica.west);
                if ( text=="podnies" && Kaplica.isItemTook==0)
                    {Geralt.GrabItem(ZbrojaWCW);
                    Kaplica.isItemTook=1;
                    }
            }
            continue;
        }
        //Palacowa1
        Level Palacowa1(30, "Ul. Pałacowa 1", "Stoisz na szerokiej drodze pokrytej pięknie ", "zdobionymi kamiennymi płytami. Z obydwu", "stron znajdują się bogate kamienice.", 0, 31, 0, 29);
        if(Game.ReturnCurrentID()==Palacowa1.ReturnID())
            {
                Palacowa1.WriteTitle();
                Palacowa1.WriteDirections();
                Palacowa1.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Palacowa1.north, Palacowa1.east, Palacowa1.south, Palacowa1.west);
            }
            continue;
        }
        //Palacowa2
        Level Palacowa2(31, "Ul. Pałacowa 2", "Stoisz na szerokiej drodze pokrytej pięknie ", "zdobionymi kamiennymi płytami. Z obydwu", "stron znajdują się bogate kamienice.", 96, 32, 91, 30);
        if(Game.ReturnCurrentID()==Palacowa2.ReturnID())
            {
                Palacowa2.WriteTitle();
                Palacowa2.WriteDirections();
                Palacowa2.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Palacowa2.north, Palacowa2.east, Palacowa2.south, Palacowa2.west);
            }
            continue;
        }
        //Palacowa3
        Level Palacowa3(32, "Ul. Pałacowa 3", "Stoisz na szerokiej drodze pokrytej pięknie ", "zdobionymi kamiennymi płytami. Z obydwu", "stron znajdują się bogate kamienice.", 0, 33, 0, 31);
        if(Game.ReturnCurrentID()==Palacowa3.ReturnID())
            {
                Palacowa3.WriteTitle();
                Palacowa3.WriteDirections();
                Palacowa3.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Palacowa3.north, Palacowa3.east, Palacowa3.south, Palacowa3.west);
            }
            continue;
        }
        //Palacowa4
        Level Palacowa4(33, "Ul. Pałacowa 4", "Stoisz na szerokiej drodze pokrytej pięknie ", "zdobionymi kamiennymi płytami. Z obydwu", "stron znajdują się bogate kamienice.", 0, 34, 0, 32);
        if(Game.ReturnCurrentID()==Palacowa4.ReturnID())
            {
                Palacowa4.WriteTitle();
                Palacowa4.WriteDirections();
                Palacowa4.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Palacowa4.north, Palacowa4.east, Palacowa4.south, Palacowa4.west);
            }
            continue;
        }
        //Palacowa5
        Level Palacowa5(34, "Ul. Pałacowa 5", "Stoisz na szerokiej drodze pokrytej pięknie ", "zdobionymi kamiennymi płytami. Z obydwu", "stron znajdują się bogate kamienice.", 35, 0, 0, 33);
        if(Game.ReturnCurrentID()==Palacowa5.ReturnID())
            {
                Palacowa5.WriteTitle();
                Palacowa5.WriteDirections();
                Palacowa5.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Palacowa5.north, Palacowa5.east, Palacowa5.south, Palacowa5.west);
            }
            continue;
        }
        //Palacowa6
        Level Palacowa6(35, "Ul. Pałacowa 6", "Stoisz na szerokiej drodze pokrytej pięknie ", "zdobionymi kamiennymi płytami. Z obydwu", "stron znajdują się bogate kamienice.", 36, 0, 34, 0);
        if(Game.ReturnCurrentID()==Palacowa6.ReturnID())
            {
                Palacowa6.WriteTitle();
                Palacowa6.WriteDirections();
                Palacowa6.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Palacowa6.north, Palacowa6.east, Palacowa6.south, Palacowa6.west);
            }
            continue;
        }
        //Palacowa7
        Level Palacowa7(36, "Ul. Pałacowa 7", "Stoisz na szerokiej drodze pokrytej pięknie ", "zdobionymi kamiennymi płytami. Z obydwu", "stron znajdują się bogate kamienice.", 0, 37, 35, 0);
        if(Game.ReturnCurrentID()==Palacowa7.ReturnID())
            {
                Palacowa7.WriteTitle();
                Palacowa7.WriteDirections();
                Palacowa7.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Palacowa7.north, Palacowa7.east, Palacowa7.south, Palacowa7.west);
            }
            continue;
        }
        //Palacowa8
        Level Palacowa8(37, "Ul. Pałacowa 8", "Stoisz na szerokiej drodze pokrytej pięknie ", "zdobionymi kamiennymi płytami. Z obydwu", "stron znajdują się bogate kamienice.", 100, 38, 0, 36);
        if(Game.ReturnCurrentID()==Palacowa8.ReturnID())
            {
                Palacowa8.WriteTitle();
                Palacowa8.WriteDirections();
                Palacowa8.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Palacowa8.north, Palacowa8.east, Palacowa8.south, Palacowa8.west);
            }
            continue;
        }
        //Palacowa9
        Level Palacowa9(38, "Ul. Pałacowa 9", "Stoisz na szerokiej drodze pokrytej pięknie ", "zdobionymi kamiennymi płytami. Z obydwu", "stron znajdują się bogate kamienice.", 0, 39, 90, 37);
        if(Game.ReturnCurrentID()==Palacowa9.ReturnID())
            {
                Palacowa9.WriteTitle();
                Palacowa9.WriteDirections();
                Palacowa9.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Palacowa9.north, Palacowa9.east, Palacowa9.south, Palacowa9.west);
            }
            continue;
        }
        //Palacowa10
        Level Palacowa10(39, "Ul. Pałacowa 10", "Stoisz na szerokiej drodze pokrytej pięknie ", "zdobionymi kamiennymi płytami. Z obydwu", "stron znajdują się bogate kamienice.", 40, 41, 0, 38);
        if(Game.ReturnCurrentID()==Palacowa10.ReturnID())
            {
                Palacowa10.WriteTitle();
                Palacowa10.WriteDirections();
                Palacowa10.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Palacowa10.north, Palacowa10.east, Palacowa10.south, Palacowa10.west);
            }
            continue;
        }
        //PŁATNERZ
        LevelWithShop Platnerz1( 40 , "Sklep płatnerski", "Stoisz koło płatnerza wybijającej ", "właśnie zbroję. Na wieszakach leżą", "pięknie zdobione pancerze.", 0, 0, 39, 0, NilfgardzkaZbroja, KeadwanskaZbroja, ZbrojaKrolestwPolnocy, UlepszonaZbrojaWCM, ArcymistrzowskaZbrojaWCW, 5);
            if(Game.ReturnCurrentID()==Platnerz1.ReturnID())
            {
                Platnerz1.WriteTitle();
                Platnerz1.WriteDirections();
                Platnerz1.WriteDescription();
                Platnerz1.WriteDescriptionOfSurroundings("Napisz \"sklep\", aby wyświetlić listę przedmiotów do kupna.");
                Platnerz1.WriteDescriptionOfSurroundings("Napisz \"kup-(numer przedmiotu z listy)\", aby kupić dany przedmiot.");
                Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Platnerz1.WriteItemList(text);
                Game.Move(text, Platnerz1.north, Platnerz1.east, Platnerz1.south, Platnerz1.west);
                if(text=="kup-1")
                    Geralt.BuyItem(Platnerz1.ReturnItem1());
                if(text=="kup-2")
                    Geralt.BuyItem(Platnerz1.ReturnItem2());
                if(text=="kup-3")
                    Geralt.BuyItem(Platnerz1.ReturnItem3());
                if(text=="kup-4")
                    Geralt.BuyItem(Platnerz1.ReturnItem4());
                if(text=="kup-5")
                    Geralt.BuyItem(Platnerz1.ReturnItem5());

            }
            continue;
        }
        //Palacowa11
        Level Palacowa11(41, "Ul. Pałacowa 11 ", "Stoisz na szerokiej drodze pokrytej pięknie ", "zdobionymi kamiennymi płytami. Z obydwu", "stron znajdują się bogate kamienice.", 0, 42, 0, 38);
        if(Game.ReturnCurrentID()==Palacowa11.ReturnID())
            {
                Palacowa11.WriteTitle();
                Palacowa11.WriteDirections();
                Palacowa11.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Palacowa11.north, Palacowa11.east, Palacowa11.south, Palacowa11.west);
            }
            continue;
        }
         //Palacowa12
        Level Palacowa12(42, "Ul. Pałacowa 12 ", "Stoisz na szerokiej drodze pokrytej pięknie ", "zdobionymi kamiennymi płytami. Z obydwu", "stron znajdują się bogate kamienice.", 0, 43, 45, 41);
        if(Game.ReturnCurrentID()==Palacowa12.ReturnID())
            {
                Palacowa12.WriteTitle();
                Palacowa12.WriteDirections();
                Palacowa12.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Palacowa12.north, Palacowa12.east, Palacowa12.south, Palacowa12.west);
            }
            continue;
        }
         //Palacowa13
        Level Palacowa13(43, "Ul. Pałacowa 13", "Stoisz na szerokiej drodze pokrytej pięknie ", "zdobionymi kamiennymi płytami. Z obydwu", "stron znajdują się bogate kamienice.", 0, 44, 0, 42);
        if(Game.ReturnCurrentID()==Palacowa13.ReturnID())
            {
                Palacowa13.WriteTitle();
                Palacowa13.WriteDirections();
                Palacowa13.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Palacowa13.north, Palacowa13.east, Palacowa13.south, Palacowa13.west);
            }
            continue;
        }
         //Zielona1
        Level Zielona1(44, "Ul. Zielona", "Stoisz na zadbanej ulicy. Z obu stron otaczają cię zakłady ", "i kamienice mieszczan, rzemieślników. Dzieci bawią się", "prymitywnymi zabawkami z drewna, biegają i grają w gry.", 0, 0, 48, 43);
        if(Game.ReturnCurrentID()==Zielona1.ReturnID())
            {
                Zielona1.WriteTitle();
                Zielona1.WriteDirections();
                Zielona1.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Zielona1.north, Zielona1.east, Zielona1.south, Zielona1.west);
            }
            continue;
        }
         //Zielona2
        Level Zielona2(45, "Ul. Zielona", "Stoisz na zadbanej ulicy. Z obu stron otaczają cię zakłady ", "i kamienice mieszczan, rzemieślników. Dzieci bawią się", "prymitywnymi zabawkami z drewna, biegają i grają w gry.", 42, 0, 46, 0);
        if(Game.ReturnCurrentID()==Zielona2.ReturnID())
            {
                Zielona2.WriteTitle();
                Zielona2.WriteDirections();
                Zielona2.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Zielona2.north, Zielona2.east, Zielona2.south, Zielona2.west);
            }
            continue;
        }
        //ZAKAMAREK
        LevelWithSimpleDialogs Zakamarek1(46, "Zakamarek", "Stoisz na ciemnej uliczce. Nie dociera", " tutaj ani jeden promień słońca.", "", 45, 47, 0, 0);
        if(Game.ReturnCurrentID()==Zakamarek1.ReturnID())
            {
                Zakamarek1.WriteTitle();
                Zakamarek1.WriteDirections();
                Zakamarek1.WriteDescription();
                Zakamarek1.IntroductionToDialog("W rogu śpi niepełnosprawny żebrak w swoim prowizorycznym schronieniu");
                Zakamarek1.WriteDescriptionOfSurroundings("Napisz \"zagadaj-zebrak\", aby porozmawiać z żebrakiem.");
                 Geralt.Fight("Grupa bandytów", 75, 15, 20);
                Game.LevelEnd=0;
                if (Geralt.isDeath())
                    {
                        Game.ChangeCurrentID(0);
                        Game.LevelEnd=1;
                    }
                else
                    Geralt.GrabMoney( 500);
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Zakamarek1.north, Zakamarek1.east, Zakamarek1.south, Zakamarek1.west);
                Zakamarek1.Dialog(text, "zebrak", "Co tutaj robisz?", "Nie masz co innego do roboty, tylko cały dzień tutaj siedzisz, pasożycie?", "Daj 1$.", "A gdzie indziej mam być?", "A ty nie masz nic innego do roboty, tylko mi rzyć zawracać", "Dziekuję. Nie wyglądasz na tutejszego, więc opowiem ci pewną legendę. Ponoć pod posągiem króla w naszym mieście ukryty jest skarb od króla Foltesta, ale nikt go jeszzcze nie znalazł. Może ci się uda.");
                if(Zakamarek1.ReturnChosenOption()==3)
                    Geralt.GrabMoney(-1);
            }
            continue;
        }
         //Zielona3
        Level Zielona3(47, "Ul. Zielona", "Stoisz na zadbanej ulicy. Z obu stron otaczają cię zakłady ", "i kamienice mieszczan, rzemieślników. Dzieci bawią się", "prymitywnymi zabawkami z drewna, biegają i grają w gry.", 0, 49, 0, 46);
        if(Game.ReturnCurrentID()==Zielona3.ReturnID())
            {
                Zielona3.WriteTitle();
                Zielona3.WriteDirections();
                Zielona3.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Zielona3.north, Zielona3.east, Zielona3.south, Zielona3.west);
            }
            continue;
        }
        //Zielona4
        Level Zielona4(48, "Ul. Zielona", "Stoisz na zadbanej ulicy. Z obu stron otaczają cię zakłady ", "i kamienice mieszczan, rzemieślników. Dzieci bawią się", "prymitywnymi zabawkami z drewna, biegają i grają w gry.", 44, 105, 49, 0);
        if(Game.ReturnCurrentID()==Zielona4.ReturnID())
            {
                Zielona4.WriteTitle();
                Zielona4.WriteDirections();
                Zielona4.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Zielona4.north, Zielona4.east, Zielona4.south, Zielona4.west);
            }
            continue;
        }
        //Zielona5
        Level Zielona5(49, "Ul. Zielona", "Stoisz na zadbanej ulicy. Z obu stron otaczają cię zakłady ", "i kamienice mieszczan, rzemieślników. Dzieci bawią się", "prymitywnymi zabawkami z drewna, biegają i grają w gry.", 48, 0, 50, 47);
        if(Game.ReturnCurrentID()==Zielona5.ReturnID())
            {
                Zielona5.WriteTitle();
                Zielona5.WriteDirections();
                Zielona5.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Zielona5.north, Zielona5.east, Zielona5.south, Zielona5.west);
            }
            continue;
        }
        //Zielona6
        Level Zielona6(50, "Ul. Zielona", "Stoisz na zadbanej ulicy. Z obu stron otaczają cię zakłady ", "i kamienice mieszczan, rzemieślników. Dzieci bawią się", "prymitywnymi zabawkami z drewna, biegają i grają w gry.", 49, 51, 52, 0);
        if(Game.ReturnCurrentID()==Zielona6.ReturnID())
            {
                Zielona6.WriteTitle();
                Zielona6.WriteDirections();
                Zielona6.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Zielona6.north, Zielona6.east, Zielona6.south, Zielona6.west);
            }
            continue;
        }
        //APTEKA
         LevelWithShop Apteka2( 51 , "Apteka", "Stoisz przed ladą, za którą stoi", "zielarz. Wokół unosi się zapach różnorodnych", "ziół. Na półkach leżą ususzone zioła.", 0, 0, 0, 50, Bandarz, MalaApteczka, DuzaApteczka, Jaskolka, Nothing, 4);
            if(Game.ReturnCurrentID()==Apteka2.ReturnID())
            {
                Apteka2.WriteTitle();
                Apteka2.WriteDirections();
                Apteka2.WriteDescription();
                Apteka2.WriteDescriptionOfSurroundings("Napisz \"sklep\", aby wyświetlić listę przedmiotów do kupna.");
                Apteka2.WriteDescriptionOfSurroundings("Napisz \"kup-(numer przedmiotu z listy)\", aby kupić dany przedmiot.");
                Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Apteka2.WriteItemList(text);
                Game.Move(text, Apteka2.north, Apteka2.east, Apteka2.south, Apteka2.west);
                if(text=="kup-1")
                    Geralt.BuyItem(Apteka2.ReturnItem1());
                if(text=="kup-2")
                    Geralt.BuyItem(Apteka2.ReturnItem2());
                if(text=="kup-3")
                    Geralt.BuyItem(Apteka2.ReturnItem3());
                if(text=="kup-4")
                    Geralt.BuyItem(Apteka2.ReturnItem4());
                if(text=="kup-5")
                    Geralt.BuyItem(Apteka2.ReturnItem5());

            }
            continue;
        }
        //Zielona7
        Level Zielona7(52, "Ul. Zielona", "Stoisz na zadbanej ulicy. Z obu stron otaczają cię zakłady ", "i kamienice mieszczan, rzemieślników. Dzieci bawią się", "prymitywnymi zabawkami z drewna, biegają i grają w gry.", 50, 0, 53, 0);
        if(Game.ReturnCurrentID()==Zielona7.ReturnID())
            {
                Zielona7.WriteTitle();
                Zielona7.WriteDirections();
                Zielona7.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Zielona7.north, Zielona7.east, Zielona7.south, Zielona7.west);
            }
            continue;
    }
        //Zielona8
        Level Zielona8(53, "Ul. Zielona", "Stoisz na zadbanej ulicy. Z obu stron otaczają cię zakłady ", "i kamienice mieszczan, rzemieślników. Dzieci bawią się", "prymitywnymi zabawkami z drewna, biegają i grają w gry.", 52, 54, 56, 0);
        if(Game.ReturnCurrentID()==Zielona8.ReturnID())
            {
                Zielona8.WriteTitle();
                Zielona8.WriteDirections();
                Zielona8.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Zielona8.north, Zielona8.east, Zielona8.south, Zielona8.west);
            }continue;

        }
        //WYRWA W MURZE
        Level Wyrwa(54, "Wyrwa w murze", "Czołgasz się pod małą wyrwą w murze. ", "Z sufitu pomału sączy się woda.", "W oddali słyszysz dziwne, przytłumione dźwięki", 0, 55, 0, 53);
        if(Game.ReturnCurrentID()==Wyrwa.ReturnID())
            {
                Wyrwa.WriteTitle();
                Wyrwa.WriteDirections();
                Wyrwa.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Wyrwa.north, Wyrwa.east, Wyrwa.south, Wyrwa.west);
            }
            continue;
        }
        //JASKINIA
    Level Jaskinia1(55, "Jaskinia", "Stoisz w ciemnej grocie. Z podłogi ", "i sufitu wyłaniają się stalaktyty,", "stalagmity, i stalagnaty.", 0, 0, 0, 54);
        if(Game.ReturnCurrentID()==Jaskinia1.ReturnID())
            {
                Jaskinia1.WriteTitle();
                Jaskinia1.WriteDirections();
                Jaskinia1.WriteDescription();
                Jaskinia1.WriteNotice("W gruzach widzisz połyskujące coś, na kształt skrzyni.");
                Jaskinia1.WriteDescriptionOfSurroundings("Napisz podnies, aby to wziąć.");
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Jaskinia1.north, Jaskinia1.east, Jaskinia1.south, Jaskinia1.west);
                 if ( text=="podnies" && Jaskinia1.isItemTook==0)
                    {Geralt.GrabMoney(3000);
                    Jaskinia1.isItemTook=1;
                    }
                    continue;
            }
        }
        //Zielona9
        Level Zielona9(56, "Ul. Zielona", "Stoisz na zadbanej ulicy. Z obu stron otaczają cię zakłady ", "i kamienice mieszczan, rzemieślników. Dzieci bawią się", "prymitywnymi zabawkami z drewna, biegają i grają w gry.", 53, 0, 57, 73);
        if(Game.ReturnCurrentID()==Zielona9.ReturnID())
            {
                Zielona9.WriteTitle();
                Zielona9.WriteDirections();
                Zielona9.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Zielona9.north, Zielona9.east, Zielona9.south, Zielona9.west);
            }
            continue;
        }
        //Zielona10
        Level Zielona10(57, "Ul. Zielona", "Stoisz na zadbanej ulicy. Z obu stron otaczają cię zakłady ", "i kamienice mieszczan, rzemieślników. Dzieci bawią się", "prymitywnymi zabawkami z drewna, biegają i grają w gry.", 56, 106, 58, 104);
        if(Game.ReturnCurrentID()==Zielona10.ReturnID())
            {
                Zielona10.WriteTitle();
                Zielona10.WriteDirections();
                Zielona10.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Zielona10.north, Zielona10.east, Zielona10.south, Zielona10.west);
            }
            continue;
        }
        //Zielona11
        Level Zielona11(58, "Ul. Zielona", "Stoisz na zadbanej ulicy. Z obu stron otaczają cię zakłady ", "i kamienice mieszczan, rzemieślników. Dzieci bawią się", "prymitywnymi zabawkami z drewna, biegają i grają w gry.", 57, 0, 59, 93);
        if(Game.ReturnCurrentID()==Zielona11.ReturnID())
            {
                Zielona11.WriteTitle();
                Zielona11.WriteDirections();
                Zielona11.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Zielona11.north, Zielona11.east, Zielona11.south, Zielona11.west);
            }
            continue;
        }
        //Zielona12
        Level Zielona12(59, "Ul. Zielona", "Stoisz na zadbanej ulicy. Z obu stron otaczają cię zakłady ", "i kamienice mieszczan, rzemieślników. Dzieci bawią się", "prymitywnymi zabawkami z drewna, biegają i grają w gry.", 58, 0, 60, 95);
        if(Game.ReturnCurrentID()==Zielona12.ReturnID())
            {
                Zielona12.WriteTitle();
                Zielona12.WriteDirections();
                Zielona12.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Zielona12.north, Zielona12.east, Zielona12.south, Zielona12.west);
            }
            continue;
        }
        //Poludniowa6
        Level Poludniowa6(60, "Ul. Poludniowa 10",  "Stoisz na niezbyt szerokiej brudnej", "drodze, która rozciąga się wzdłuż", "muru.", 59, 0, 0, 61);
        if(Game.ReturnCurrentID()==Poludniowa6.ReturnID())
            {
                Poludniowa6.WriteTitle();
                Poludniowa6.WriteDirections();
                Poludniowa6.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Poludniowa6.north, Poludniowa6.east, Poludniowa6.south, Poludniowa6.west);
            }
            continue;
        }
        //Poludniowa7
        Level Poludniowa7(61, "Ul. Poludniowa 9",  "Stoisz na niezbyt szerokiej brudnej", "drodze, która rozciąga się wzdłuż", "muru.", 95, 60, 0, 62);
        if(Game.ReturnCurrentID()==Poludniowa7.ReturnID())
            {
                Poludniowa7.WriteTitle();
                Poludniowa7.WriteDirections();
                Poludniowa7.WriteDescription();
                Poludniowa7.WriteNotice("Koło krawężnika coś się dziwnie błyszczy");
                Poludniowa7.WriteDescriptionOfSurroundings("Napisz podnies, aby to wziąć.");
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Poludniowa7.north, Poludniowa7.east, Poludniowa7.south, Poludniowa7.west);
                if ( text=="podnies" && Poludniowa7.isItemTook==0)
                    {Geralt.GrabItem(StalowyMiecz);
                    Poludniowa7.isItemTook=1;
                    }
            }
            continue;
        }
        //Poludniowa8
        Level Poludniowa8(62, "Ul. Poludniowa 8",  "Stoisz na niezbyt szerokiej brudnej", "drodze, która rozciąga się wzdłuż", "muru.", 94, 61, 0, 63);
        if(Game.ReturnCurrentID()==Poludniowa8.ReturnID())
            {
                Poludniowa8.WriteTitle();
                Poludniowa8.WriteDirections();
                Poludniowa8.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Poludniowa8.north, Poludniowa8.east, Poludniowa8.south, Poludniowa8.west);
            }
            continue;
        }
        //Poludniowa9
        Level Poludniowa9(63, "Ul. Poludniowa 7",  "Stoisz na niezbyt szerokiej brudnej", "drodze, która rozciąga się wzdłuż", "muru.", 0, 62, 0, 64);
        if(Game.ReturnCurrentID()==Poludniowa9.ReturnID())
            {
                Poludniowa9.WriteTitle();
                Poludniowa9.WriteDirections();
                Poludniowa9.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Poludniowa9.north, Poludniowa9.east, Poludniowa9.south, Poludniowa9.west);
            }
            continue;
        }
        //Poludniowa10
        Level Poludniowa10(64, "Ul. Poludniowa 6",  "Stoisz na niezbyt szerokiej brudnej", "drodze, która rozciąga się wzdłuż", "muru.", 65, 63, 0, 2);
        if(Game.ReturnCurrentID()==Poludniowa10.ReturnID())
            {
                Poludniowa10.WriteTitle();
                Poludniowa10.WriteDirections();
                Poludniowa10.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Poludniowa10.north, Poludniowa10.east, Poludniowa10.south, Poludniowa10.west);
            }
            continue;
        }
        // Oboz;
        Level Oboz(65, "Obóz treningowy", "Stoisz na placu, koło dużego", "namiotu. Wokół ciebie żołnierze ćwiczą", "fechtunek, strzelanie z łuku.", 0, 0, 64, 66);
        if(Game.ReturnCurrentID()==Oboz.ReturnID())
            {
                Oboz.WriteTitle();
                Oboz.WriteDirections();
                Oboz.WriteDescription();
                Geralt.Fight("Kukła", 100, 0, 100);
                Game.LevelEnd=0;
                if (Geralt.isDeath())
                    {
                        Game.ChangeCurrentID(0);
                        Game.LevelEnd=1;
                    }
                else
                    Geralt.GrabMoney(0);
                while (Game.LevelEnd==0)
                {

                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Oboz.north, Oboz.east, Oboz.south, Oboz.west);
            }
            continue;
            }
        //Centralna1
        Level Centralna1(66, "Ul. Centralna 1",  "Stoisz na szerokiej ulicy, na której", "okoliczni chłopi rozstawili swoje", "stragany. Panuje tu gwar i szum.", 67, 65, 2, 0);
        if(Game.ReturnCurrentID()==Centralna1.ReturnID())
            {
                Centralna1.WriteTitle();
                Centralna1.WriteDirections();
                Centralna1.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Centralna1.north, Centralna1.east, Centralna1.south, Centralna1.west);
            }
            continue;
        }
        //Centralna2
        Level Centralna2(67, "Ul. Centralna 2",  "Stoisz na szerokiej ulicy, na której", "okoliczni chłopi rozstawili swoje", "stragany. Panuje tu gwar i szum.", 68, 0, 66, 0);
        if(Game.ReturnCurrentID()==Centralna2.ReturnID())
            {
                Centralna2.WriteTitle();
                Centralna2.WriteDirections();
                Centralna2.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Centralna2.north, Centralna2.east, Centralna2.south, Centralna2.west);
            }
            continue;
        }
        //Centralna3
        Level Centralna3(68, "Ul. Centralna 3",  "Stoisz na szerokiej ulicy, na której", "okoliczni chłopi rozstawili swoje", "stragany. Panuje tu gwar i szum.", 69, 102, 67, 0);
        if(Game.ReturnCurrentID()==Centralna3.ReturnID())
            {
                Centralna3.WriteTitle();
                Centralna3.WriteDirections();
                Centralna3.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Centralna3.north, Centralna3.east, Centralna3.south, Centralna3.west);
            }
            continue;
        }
       //Rynek1
         Level Rynek1(69, "Rynek 1",  "Stoisz na zatłoczonym placu pokrytym", "małej wielkości, kamiennymi płytami. Wokól", "ciebie rozstawione są stragany.", 77, 70, 68, 78);
        if(Game.ReturnCurrentID()==Rynek1.ReturnID())
            {
                Rynek1.WriteTitle();
                Rynek1.WriteDirections();
                Rynek1.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Rynek1.north, Rynek1.east, Rynek1.south, Rynek1.west);
            }
            continue;
        }
        //Rynek2
         Level Rynek2(70, "Rynek 2",  "Stoisz na zatłoczonym placu pokrytym", "małej wielkości, kamiennymi płytami. Wokól", "ciebie rozstawione są stragany.", 74, 71, 102, 69);
        if(Game.ReturnCurrentID()==Rynek2.ReturnID())
            {
                Rynek2.WriteTitle();
                Rynek2.WriteDirections();
                Rynek2.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Rynek2.north, Rynek2.east, Rynek2.south, Rynek2.west);
            }
            continue;
        }
         //Centralna4
        Level Centralna4(71, "Ul. Centralna 4",  "Stoisz na szerokiej ulicy, na której", "okoliczni chłopi rozstawili swoje", "stragany. Panuje tu gwar i szum.", 0, 72, 0, 70);
        if(Game.ReturnCurrentID()==Centralna4.ReturnID())
            {
                Centralna4.WriteTitle();
                Centralna4.WriteDirections();
                Centralna4.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Centralna4.north, Centralna4.east, Centralna4.south, Centralna4.west);
            }
            continue;
        }
         //Centralna5
        Level Centralna5(72, "Ul. Centralna 5",  "Stoisz na szerokiej ulicy, na której", "okoliczni chłopi rozstawili swoje", "stragany. Panuje tu gwar i szum.", 0, 73, 0, 71);
        if(Game.ReturnCurrentID()==Centralna5.ReturnID())
            {
                Centralna5.WriteTitle();
                Centralna5.WriteDirections();
                Centralna5.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Centralna5.north, Centralna5.east, Centralna5.south, Centralna5.west);
            }
            continue;
        }
         //Centralna6
        Level Centralna6(73, "Ul. Centralna 6",  "Stoisz na szerokiej ulicy, na której", "okoliczni chłopi rozstawili swoje", "stragany. Panuje tu gwar i szum.", 0, 56, 104, 72);
        if(Game.ReturnCurrentID()==Centralna6.ReturnID())
            {
                Centralna6.WriteTitle();
                Centralna6.WriteDirections();
                Centralna6.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Centralna6.north, Centralna6.east, Centralna6.south, Centralna6.west);
            }
            continue;
        }
        //Rynek3
         Level Rynek3(74, "Rynek 3",  "Stoisz na zatłoczonym placu pokrytym", "małej wielkości, kamiennymi płytami. Wokól", "ciebie rozstawione są stragany.", 75, 0, 70, 77);
        if(Game.ReturnCurrentID()==Rynek3.ReturnID())
            {
                Rynek3.WriteTitle();
                Rynek3.WriteDirections();
                Rynek3.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Rynek3.north, Rynek3.east, Rynek3.south, Rynek3.west);
            }
            continue;
        }
        //Rynek4
         Level Rynek4(75, "Rynek 4",  "Stoisz na zatłoczonym placu pokrytym", "małej wielkości, kamiennymi płytami. Wokól", "ciebie rozstawione są stragany.", 0, 76, 74, 87);
        if(Game.ReturnCurrentID()==Rynek4.ReturnID())
            {
                Rynek4.WriteTitle();
                Rynek4.WriteDirections();
                Rynek4.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Rynek4.north, Rynek4.east, Rynek4.south, Rynek4.west);
            }
            continue;
        }
        //Platnerz
        LevelWithShop Platnerz2( 76 , "Sklep płatnerski", "Stoisz koło płatnerza wybijającej ", "właśnie zbroję. Na wieszakach leżą", "pięknie zdobione pancerze.", 0, 0, 0, 75, NilfgardzkaZbroja, KeadwanskaZbroja, ZbrojaKrolestwPolnocy, UlepszonaZbrojaWCM, UlepszonaZbrojaWCW, 5);
            if(Game.ReturnCurrentID()==Platnerz2.ReturnID())
            {
                Platnerz2.WriteTitle();
                Platnerz2.WriteDirections();
                Platnerz2.WriteDescription();
                Platnerz2.WriteDescriptionOfSurroundings("Napisz \"sklep\", aby wyświetlić listę przedmiotów do kupna.");
                Platnerz2.WriteDescriptionOfSurroundings("Napisz \"kup-(numer przedmiotu z listy)\", aby kupić dany przedmiot.");
                Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Platnerz2.WriteItemList(text);
                Game.Move(text, Platnerz2.north, Platnerz2.east, Platnerz2.south, Platnerz2.west);
                if(text=="kup-1")
                    Geralt.BuyItem(Platnerz2.ReturnItem1());
                if(text=="kup-2")
                    Geralt.BuyItem(Platnerz2.ReturnItem2());
                if(text=="kup-3")
                    Geralt.BuyItem(Platnerz2.ReturnItem3());
                if(text=="kup-4")
                    Geralt.BuyItem(Platnerz2.ReturnItem4());
                if(text=="kup-5")
                    Geralt.BuyItem(Platnerz2.ReturnItem5());
                }
                continue;
            }
        //Fontanna
        Level Fontanna(77, "Fontanna",  "Stoisz przed wielką-9 metrową fontanną", "z bogato zdobionymi rzeźbiami po bokach", "i wielkim posągiem na środku.", 87, 74, 69, 81);
        if(Game.ReturnCurrentID()==Fontanna.ReturnID())
            {
                Fontanna.WriteTitle();
                Fontanna.WriteDirections();
                Fontanna.WriteDescription();
                Fontanna.WriteNotice("W wodzie coś dziwnie błyszczy");
                Fontanna.WriteDescriptionOfSurroundings("Napisz podnies, aby to wziąć.");
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Fontanna.north, Fontanna.east, Fontanna.south, Fontanna.west);
                if ( text=="podnies" && Fontanna.isItemTook==0)
                    {Geralt.GrabItem(StalowyMiecz);
                    Fontanna.isItemTook=1;
                    }
            }
            continue;
        }
        //Rynek5
         Level Rynek5(78, "Rynek 8",  "Stoisz na zatłoczonym placu pokrytym", "małej wielkości, kamiennymi płytami. Wokól", "ciebie rozstawione są stragany.", 81, 69, 0, 79);
        if(Game.ReturnCurrentID()==Rynek5.ReturnID())
            {
                Rynek5.WriteTitle();
                Rynek5.WriteDirections();
                Rynek5.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Rynek5.north, Rynek5.east, Rynek5.south, Rynek5.west);
            }
            continue;
        }
        //APTEKA
         LevelWithShop Apteka3( 79 , "Apteka", "Stoisz przed ladą, za którą stoi", "zielarz. Wokół unosi się zapach różnorodnych", "ziół. Na półkach leżą ususzone zioła.", 80, 78, 0, 0, Bandarz, MalaApteczka, DuzaApteczka, Jaskolka, Nothing, 4);
            if(Game.ReturnCurrentID()==Apteka3.ReturnID())
            {
                Apteka3.WriteTitle();
                Apteka3.WriteDirections();
                Apteka3.WriteDescription();
                Apteka3.WriteDescriptionOfSurroundings("Napisz \"sklep\", aby wyświetlić listę przedmiotów do kupna.");
                Apteka3.WriteDescriptionOfSurroundings("Napisz \"kup-(numer przedmiotu z listy)\", aby kupić dany przedmiot.");
                Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Apteka3.WriteItemList(text);
                Game.Move(text, Apteka3.north, Apteka3.east, Apteka3.south, Apteka3.west);
                if(text=="kup-1")
                    Geralt.BuyItem(Apteka3.ReturnItem1());
                if(text=="kup-2")
                    Geralt.BuyItem(Apteka3.ReturnItem2());
                if(text=="kup-3")
                    Geralt.BuyItem(Apteka3.ReturnItem3());
                if(text=="kup-4")
                    Geralt.BuyItem(Apteka3.ReturnItem4());
                if(text=="kup-5")
                    Geralt.BuyItem(Apteka3.ReturnItem5());
            }
            continue;
        }
        //KOWAL
            LevelWithShop Kowal2( 80 , "Kowal", "Stoisz koło umieśnionego kowala. Po twojej lewej", "stronie znajduje się kowadło oraz piec hutniczy,", "a po prawej stoją stojaki z mieczami.", 83, 81, 79, 0, TemerskiMiecz, NilfgardzkiMiecz, Ementaler, SrebrnyMWCKota, Zerwikaptur, 5);
            if(Game.ReturnCurrentID()==Kowal2.ReturnID())
            {
                Kowal2.WriteTitle();
                Kowal2.WriteDirections();
                Kowal2.WriteDescription();
                Kowal2.WriteDescriptionOfSurroundings("Napisz \"sklep\", aby wyświetlić listę przedmiotów do kupna.");
                Kowal2.WriteDescriptionOfSurroundings("Napisz \"kup-(numer przedmiotu z listy)\", aby kupić dany przedmiot.");
                Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Kowal2.WriteItemList(text);
                Game.Move(text, Kowal2.north, Kowal2.east, Kowal2.south, Kowal2.west);
                if(text=="kup-1")
                    Geralt.BuyItem(Kowal2.ReturnItem1());
                if(text=="kup-2")
                    Geralt.BuyItem(Kowal2.ReturnItem2());
                if(text=="kup-3")
                    Geralt.BuyItem(Kowal2.ReturnItem3());
                if(text=="kup-4")
                    Geralt.BuyItem(Kowal2.ReturnItem4());
                if(text=="kup-5")
                    Geralt.BuyItem(Kowal2.ReturnItem5());
            }
            continue;
        }
        //Rynek6
         Level Rynek6(81, "Rynek 7",  "Stoisz na zatłoczonym placu pokrytym", "małej wielkości, kamiennymi płytami. Wokól", "ciebie rozstawione są stragany.", 82, 77, 78, 80);
        if(Game.ReturnCurrentID()==Rynek6.ReturnID())
            {
                Rynek6.WriteTitle();
                Rynek6.WriteDirections();
                Rynek6.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Rynek6.north, Rynek6.east, Rynek6.south, Rynek6.west);
            }
            continue;
        }
        //Rynek7
         Level Rynek7(82, "Rynek 6",  "Stoisz na zatłoczonym placu pokrytym", "małej wielkości, kamiennymi płytami. Wokól", "ciebie rozstawione są stragany.", 0, 87, 81, 83);
        if(Game.ReturnCurrentID()==Rynek7.ReturnID())
            {
                Rynek7.WriteTitle();
                Rynek7.WriteDirections();
                Rynek7.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Rynek7.north, Rynek7.east, Rynek7.south, Rynek7.west);
            }
            continue;
        }
         //Centralna7
        Level Centralna7(83, "Ul. Centralna 7",  "Stoisz na szerokiej ulicy, na której", "okoliczni chłopi rozstawili swoje", "stragany. Panuje tu gwar i szum.", 0, 82, 80, 84);
        if(Game.ReturnCurrentID()==Centralna7.ReturnID())
            {
                Centralna7.WriteTitle();
                Centralna7.WriteDirections();
                Centralna7.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Centralna7.north, Centralna7.east, Centralna7.south, Centralna7.west);
            }
            continue;
        }
         //Centralna8
        Level Centralna8(84, "Ul. Centralna 8",  "Stoisz na szerokiej ulicy, na której", "okoliczni chłopi rozstawili swoje", "stragany. Panuje tu gwar i szum.", 0, 83, 0, 85);
        if(Game.ReturnCurrentID()==Centralna8.ReturnID())
            {
                Centralna8.WriteTitle();
                Centralna8.WriteDirections();
                Centralna8.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Centralna8.north, Centralna8.east, Centralna8.south, Centralna8.west);
            }
            continue;
        }
         //Centralna9
        Level Centralna9(85, "Ul. Centralna 9",  "Stoisz na szerokiej ulicy, na której", "okoliczni chłopi rozstawili swoje", "stragany. Panuje tu gwar i szum.", 0, 84, 86, 0);
        if(Game.ReturnCurrentID()==Centralna9.ReturnID())
            {
                Centralna9.WriteTitle();
                Centralna9.WriteDirections();
                Centralna9.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Centralna9.north, Centralna9.east, Centralna9.south, Centralna9.west);
            }
            continue;
        }
        //ZAKAMAREK
        LevelWithSimpleDialogs Zakamarek2(86, "Zakamarek", "Stoisz na ciemnej uliczce. Nie dociera", " tutaj ani jeden promień słońca.", "", 85, 0, 0, 0);
        if(Game.ReturnCurrentID()==Zakamarek2.ReturnID())
            {
                Zakamarek2.WriteTitle();
                Zakamarek2.WriteDirections();
                Zakamarek2.WriteDescription();
                Zakamarek2.IntroductionToDialog("W rogu śpi niepełnosprawny żebrak w swoim prowizorycznym schronieniu");
                Zakamarek2.WriteDescriptionOfSurroundings("Napisz \"zagadaj-zebrak\", aby porozmawiać z żebrakiem.");
                 Geralt.Fight("Grupa bandytów", 75, 45, 20);
                Game.LevelEnd=0;
                if (Geralt.isDeath())
                    {
                        Game.ChangeCurrentID(0);
                        Game.LevelEnd=1;
                    }
                else
                    Geralt.GrabMoney(500);
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Zakamarek2.north, Zakamarek2.east, Zakamarek2.south, Zakamarek2.west);
                Zakamarek2.Dialog(text, "zebrak", "Co tutaj robisz?", "Nie masz co innego do roboty, tylko cały dzień tutaj siedzisz, pasożycie?", "Daj 1$", "A gdzie indziej mam być?", "A ty nie masz nic innego do roboty, tylko mi rzyć zawracać", "Dziekuję. Nie wyglądasz na tutejszego, więc opowiem ci pewną legendę. Ponoć pod posągiem króla w naszym mieście ukryty jest skarb od króla Foltesta, ale nikt go jeszzcze nie znalazł. Może ci się uda.");
                if(Zakamarek1.ReturnChosenOption()==3)
                    Geralt.GrabMoney(-1);

            }
            continue;
        }
        //Rynek8
         Level Rynek8(87, "Rynek 5",  "Stoisz na zatłoczonym placu pokrytym", "małej wielkości, kamiennymi płytami. Wokól", "ciebie rozstawione są stragany.", 88, 75, 77, 82);
        if(Game.ReturnCurrentID()==Rynek8.ReturnID())
            {
                Rynek8.WriteTitle();
                Rynek8.WriteDirections();
                Rynek8.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Rynek8.north, Rynek8.east, Rynek8.south, Rynek8.west);
            }
            continue;
        }
         //Centralna10
        Level Centralna10(88, "Ul. Centralna 10",  "Stoisz na szerokiej ulicy, na której", "okoliczni chłopi rozstawili swoje", "stragany. Panuje tu gwar i szum.", 89, 0, 87, 0);
        if(Game.ReturnCurrentID()==Centralna10.ReturnID())
            {
                Centralna10.WriteTitle();
                Centralna10.WriteDirections();
                Centralna10.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Centralna10.north, Centralna10.east, Centralna10.south, Centralna10.west);
            }
            continue;
        }
         //Centralna11
        Level Centralna11(89, "Ul. Centralna 11",  "Stoisz na szerokiej ulicy, na której", "okoliczni chłopi rozstawili swoje", "stragany. Panuje tu gwar i szum.", 90, 103, 88, 0);
        if(Game.ReturnCurrentID()==Centralna11.ReturnID())
            {
                Centralna11.WriteTitle();
                Centralna11.WriteDirections();
                Centralna11.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Centralna11.north, Centralna11.east, Centralna11.south, Centralna11.west);
            }
            continue;
        }
         //Centralna12
        Level Centralna12(90, "Ul. Centralna 12",  "Stoisz na szerokiej ulicy, na której", "okoliczni chłopi rozstawili swoje", "stragany. Panuje tu gwar i szum.", 38, 0, 89, 0);
        if(Game.ReturnCurrentID()==Centralna12.ReturnID())
            {
                Centralna12.WriteTitle();
                Centralna12.WriteDirections();
                Centralna12.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Centralna12.north, Centralna12.east, Centralna12.south, Centralna12.west);

        }
        continue;
        }
        //KOWAL
        LevelWithShop Kowal3( 91 , "Kowal", "Stoisz koło umieśnionego kowala. Po twojej lewej", "stronie znajduje się kowadło oraz piec hutniczy,", "a po prawej stoją stojaki z mieczami.", 31, 0, 0, 0, TemerskiMiecz, NilfgardzkiMiecz, Ementaler, SrebrnyMWCKota, DumaPolnocy, 5);
            if(Game.ReturnCurrentID()==Kowal3.ReturnID())
            {
                Kowal3.WriteTitle();
                Kowal3.WriteDirections();
                Kowal3.WriteDescription();
                Kowal3.WriteDescriptionOfSurroundings("Napisz \"sklep\", aby wyświetlić listę przedmiotów do kupna.");
                Kowal3.WriteDescriptionOfSurroundings("Napisz \"kup-(numer przedmiotu z listy)\", aby kupić dany przedmiot.");
                Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Kowal3.WriteItemList(text);
                Game.Move(text, Kowal3.north, Kowal3.east, Kowal3.south, Kowal3.west);
                if(text=="kup-1")
                    Geralt.BuyItem(Kowal3.ReturnItem1());
                if(text=="kup-2")
                    Geralt.BuyItem(Kowal3.ReturnItem2());
                if(text=="kup-3")
                    Geralt.BuyItem(Kowal3.ReturnItem3());
                if(text=="kup-4")
                    Geralt.BuyItem(Kowal3.ReturnItem4());
                if(text=="kup-5")
                    Geralt.BuyItem(Kowal3.ReturnItem5());

            }
            continue;
        }
        //Pomnik Venzlawa
        LevelWithSimpleDialogs PomnikVenzlawa(92, "Pomnik Venzlawa", "Stoisz przed wielkim posągiem króla", "Brugge - Venzlawa. Ubrany jest w płaszcz i koronę.", "W ręku trzyma berło przypominające dzwignie.", 0, 93, 94, 0);
        if(Game.ReturnCurrentID()==PomnikVenzlawa.ReturnID())
            {
                PomnikVenzlawa.WriteTitle();
                PomnikVenzlawa.WriteDirections();
                PomnikVenzlawa.WriteDescription();
                PomnikVenzlawa.IntroductionToDialog("Mężczyzna dziwnie się na ciebie patrzy.");
                PomnikVenzlawa.WriteDescriptionOfSurroundings("Napisz \"uzyj\" ,aby pociągnąć za berło ;) " );
                PomnikVenzlawa.WriteDescriptionOfSurroundings("Napisz \"zagadaj-mezczyzna\", aby porozmawiać z mężczyzną.");
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, PomnikVenzlawa.north, PomnikVenzlawa.east, PomnikVenzlawa.south, PomnikVenzlawa.west);
                PomnikVenzlawa.Dialog(text, "mezczyzna", "Kto to jest?", "Po co powstał ten pomnik?", "Nie ważne.","Venzlav, król Brugge, lennik Cintry, potem Temerii.", "Aby upamiętnić wojnę z Nilfgardem, w której wzięli udział uchodźcy z Cintry.", "Mhmm...");
                if (text=="uzyj")
                {
                    cout<<"Otworzyła się pod tobą zapadnia i spadłeś na dół"<<endl;
                    Game.ChangeCurrentID(55);
                    Game.LevelEnd=1;
                }
            }
            continue;
        }
         //PlacVenzlawa1
        Level PlacVenzlawa1(93, "Plac Venzlawa",  "Stoisz na placu, na którym", "ustawione są równolegle ławki", "i rabatki z czerwonymi różami.", 104, 58, 95, 92);
        if(Game.ReturnCurrentID()==PlacVenzlawa1.ReturnID())
            {
                PlacVenzlawa1.WriteTitle();
                PlacVenzlawa1.WriteDirections();
                PlacVenzlawa1.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, PlacVenzlawa1.north, PlacVenzlawa1.east, PlacVenzlawa1.south, PlacVenzlawa1.west);
            }
            continue;
        }
         //PlacVenzlawa2
        Level PlacVenzlawa2(94, "Plac Venzlawa",  "Stoisz na placu, na którym", "ustawione są równolegle ławki", "i rabatki z czerwonymi różami.", 92, 95, 95, 0);
        if(Game.ReturnCurrentID()==PlacVenzlawa2.ReturnID())
            {
                PlacVenzlawa2.WriteTitle();
                PlacVenzlawa2.WriteDirections();
                PlacVenzlawa2.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, PlacVenzlawa2.north, PlacVenzlawa2.east, PlacVenzlawa2.south, PlacVenzlawa2.west);
            }
            continue;
        }
        //PlacVenzlawa3
        Level PlacVenzlawa3(95, "Plac Venzlawa",  "Stoisz na placu, na którym", "ustawione są równolegle ławki", "i rabatki z czerwonymi różami.", 93, 59, 61, 94);
        if(Game.ReturnCurrentID()==PlacVenzlawa3.ReturnID())
            {
                PlacVenzlawa3.WriteTitle();
                PlacVenzlawa3.WriteDirections();
                PlacVenzlawa3.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, PlacVenzlawa3.north, PlacVenzlawa3.east, PlacVenzlawa3.south, PlacVenzlawa3.west);
            }
            continue;
        }
      //DziedziniecZamek
        Level DziedziniecZamek(96, "Dziedziniec zamku",  "Stoisz na dużym pałacu, na którego", "środku znajduje się fontanna, a za nią", "schody prowadzące do pałacu.", 98, 0, 31, 0);
        if(Game.ReturnCurrentID()==DziedziniecZamek.ReturnID())
            {
                DziedziniecZamek.WriteTitle();
                DziedziniecZamek.WriteDirections();
                DziedziniecZamek.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, DziedziniecZamek.north, DziedziniecZamek.east, DziedziniecZamek.south, DziedziniecZamek.west);
            }
            continue;
        }
      //SalaTronowa  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!****************************************************!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        Level SalaTronowa(97, "Sala tronowa",  "Stoisz w wielkiej sali pokrytej czerwonym dywanem.", "Wzdłuż drogi do tronu, przed kolumnami stoją stojaki", "ze zbroją wykonaną przez najlepszych płatnerzy.", 0, 98, 0, 0);
        if(Game.ReturnCurrentID()==SalaTronowa.ReturnID())
            {
                SalaTronowa.WriteTitle();
                SalaTronowa.WriteDirections();
                SalaTronowa.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, SalaTronowa.north, SalaTronowa.east, SalaTronowa.south, SalaTronowa.west);
            }
            continue;
        }
      //KorytarzZamek
        Level KorytarzZamek(98, "Korytarz pałacu",  "Stoisz w długim pomieszczeniu. Na tutejszych", "ścianach wiszą piękne obrazy, a w gablotach", "widnieją rzeźby najwspanialszych artystów.", 0, 99, 96, 97);
        if(Game.ReturnCurrentID()==KorytarzZamek.ReturnID())
            {
                KorytarzZamek.WriteTitle();
                KorytarzZamek.WriteDirections();
                KorytarzZamek.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, KorytarzZamek.north, KorytarzZamek.east, KorytarzZamek.south, KorytarzZamek.west);
            }
            continue;
        }
     //ZbrojowniaZamek
        Level ZbrojowniaZamek(99, "Zbrojownia",  "Stoisz w pomieszczeniu pełnym zbroji,", "mieczy, łuków, kusz, szbli na wieszakach, podporach", "i stojakach.", 0, 0, 0, 98);
        if(Game.ReturnCurrentID()==ZbrojowniaZamek.ReturnID())
            {
                ZbrojowniaZamek.WriteTitle();
                ZbrojowniaZamek.WriteDirections();
                ZbrojowniaZamek.WriteDescription();
                ZbrojowniaZamek.WriteNotice("Na wieszaku wisi wiedźmiński miecz.");
                ZbrojowniaZamek.WriteDescriptionOfSurroundings("Napisz \"podnies\", aby wziąć ten miecz. ");
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, ZbrojowniaZamek.north, ZbrojowniaZamek.east, ZbrojowniaZamek.south, ZbrojowniaZamek.west);
                if ( text=="podnies" && Fontanna.isItemTook==0)
                    {Geralt.GrabItem(StalowyMiecz);
                    Fontanna.isItemTook=1;
                    }
            }
            continue;
        }
    // OpuszczonyDom1;
        Level OpuszczonyDom1(100, "Opuszczony dom", "Stoisz w pomieszczeniu pełnym pajęczyn", "i starych, okurzonych mebli. W powybijanych", "oknach wiszą podarte zasłony.", 0, 21, 0, 0);
        if(Game.ReturnCurrentID()==OpuszczonyDom1.ReturnID())
            {
                OpuszczonyDom1.WriteTitle();
                OpuszczonyDom1.WriteDirections();
                OpuszczonyDom1.WriteDescription();
                Geralt.Fight("Katakan", 60, 20, 5);
                Game.LevelEnd=0;
                if (Geralt.isDeath())
                    {
                        Game.ChangeCurrentID(0);
                        Game.LevelEnd=1;
                    }
                else
                    Geralt.GrabMoney(50);
                while (Game.LevelEnd==0)
                {

                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, OpuszczonyDom1.north, OpuszczonyDom1.east, OpuszczonyDom1.south, OpuszczonyDom1.west);
            }
            continue;
            }
        // NawiedzDom1;
        Level NawiedzonyDom1(101, "Nawiedzony dom", "Stoisz w pomieszczeniu pełnym pajęczyn", "i starych, okurzonych mebli. W powybijanych", "oknach wiszą podate zasłony.", 0, 0, 37, 0);
        if(Game.ReturnCurrentID()==NawiedzonyDom1.ReturnID())
            {
                NawiedzonyDom1.WriteTitle();
                NawiedzonyDom1.WriteDirections();
                NawiedzonyDom1.WriteDescription();
                Geralt.Fight("Zjawa ", 100, 40, 100);
                Game.LevelEnd=0;
                if (Geralt.isDeath())
                    {
                        Game.ChangeCurrentID(0);
                        Game.LevelEnd=1;
                    }
                else
                    Geralt.GrabMoney(150);
                while (Game.LevelEnd==0)
                {

                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, NawiedzonyDom1.north, NawiedzonyDom1.east, NawiedzonyDom1.south, NawiedzonyDom1.west);
            }
            continue;
            }
         // WscieklePiesci1
        Level WscieklePiesci1(102, "Ulica", "Obok ciebie stoi tłum ludzi patrzących", "się na walczących pięściarzy.", "Buchmacher zachęca do zakładów.", 70, 0, 0, 68);
        if(Game.ReturnCurrentID()==WscieklePiesci1.ReturnID())
            {
                WscieklePiesci1.WriteTitle();
                WscieklePiesci1.WriteDirections();
                WscieklePiesci1.WriteDescription();
                WscieklePiesci1.WriteDescriptionOfSurroundings("Napisz \"akceptuj\", aby wziąć udział w walce.");
                Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                if(text=="akceptuj")
                {
                    Geralt.Fight("Pieściarz ", 30, 10, 3);
                    if (Geralt.isDeath())
                    {
                        Game.ChangeCurrentID(0);
                        Game.LevelEnd=1;
                    }
                else
                    Geralt.GrabMoney(30);
                }
                Game.Move(text, WscieklePiesci1.north, WscieklePiesci1.east, WscieklePiesci1.south, WscieklePiesci1.west);
            }
            continue;
            }
        // WscieklePiesci2
        Level WscieklePiesci2(103, "Ulica", "Obok ciebie stoi tłum ludzi patrzących", "się na walczących pięściarzy.", "Buchmacher zachęca do zakładów.", 0, 0, 0, 89);
        if(Game.ReturnCurrentID()==WscieklePiesci2.ReturnID())
            {
                WscieklePiesci2.WriteTitle();
                WscieklePiesci2.WriteDirections();
                WscieklePiesci2.WriteDescription();
                WscieklePiesci2.WriteDescriptionOfSurroundings("Napisz \"akceptuj\", aby wziąć udział w walce.");
                Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                if(text=="akceptuj")
                {
                    Geralt.Fight("Pieściarz ", 50, 15, 3);
                    if (Geralt.isDeath())
                    {
                        Game.ChangeCurrentID(0);
                        Game.LevelEnd=1;
                    }
                else
                    Geralt.GrabMoney(50);
                }
                Game.Move(text, WscieklePiesci2.north, WscieklePiesci2.east, WscieklePiesci2.south, WscieklePiesci2.west);
            }
            continue;
            }
        // WscieklePiesci3
        Level WscieklePiesci3(104, "Ulica", "Obok ciebie stoi tłum ludzi patrzących", "się na walczących pięściarzy.", "Buchmacher zachęca do zakładów.", 73, 57, 93, 0);
        if(Game.ReturnCurrentID()==WscieklePiesci3.ReturnID())
            {
                WscieklePiesci3.WriteTitle();
                WscieklePiesci3.WriteDirections();
                WscieklePiesci3.WriteDescription();
                WscieklePiesci3.WriteDescriptionOfSurroundings("Napisz \"akceptuj\", aby wziąć udział w walce.");
                Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                if(text=="akceptuj")
                {
                    Geralt.Fight("Pieściarz ", 40, 10, 3);
                    if (Geralt.isDeath())
                    {
                        Game.ChangeCurrentID(0);
                        Game.LevelEnd=1;
                    }
                else
                    Geralt.GrabMoney(40);
                }
                Game.Move(text, WscieklePiesci3.north, WscieklePiesci3.east, WscieklePiesci3.south, WscieklePiesci3.west);
            }
            continue;
            }
        // WscieklePiesci4
        Level WscieklePiesci4(105, "Ulica", "Obok ciebie stoi tłum ludzi patrzących", "się na walczących pięściarzy.", "Buchmacher zachęca do zakładów.", 0, 0, 0, 48);
        if(Game.ReturnCurrentID()==WscieklePiesci4.ReturnID())
            {
                WscieklePiesci4.WriteTitle();
                WscieklePiesci4.WriteDirections();
                WscieklePiesci4.WriteDescription();
                WscieklePiesci4.WriteDescriptionOfSurroundings("Napisz \"akceptuj\", aby wziąć udział w walce.");
                Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                if(text=="akceptuj")
                {
                    Geralt.Fight("Pieściarz ", 60, 15, 3);
                    if (Geralt.isDeath())
                    {
                        Game.ChangeCurrentID(0);
                        Game.LevelEnd=1;
                    }
                else
                    Geralt.GrabMoney(60);
                }
                Game.Move(text, WscieklePiesci4.north, WscieklePiesci4.east, WscieklePiesci4.south, WscieklePiesci4.west);
            }
            continue;
            }

            //PLATNERZ
            LevelWithShop Platnerz3( 106 , "Sklep płatnerski", "Stoisz koło płatnerza wybijającej ", "właśnie zbroję. Na wieszakach leżą", "pięknie zdobione pancerze.", 0, 0, 57, 0, NilfgardzkaZbroja, KeadwanskaZbroja, ZbrojaKrolestwPolnocy, UlepszonaZbrojaWCM, UlepszonaZbrojaWCK, 5);
            if(Game.ReturnCurrentID()==Platnerz3.ReturnID())
            {
                Platnerz3.WriteTitle();
                Platnerz3.WriteDirections();
                Platnerz3.WriteDescription();
                Platnerz3.WriteDescriptionOfSurroundings("Napisz \"sklep\", aby wyświetlić listę przedmiotów do kupna.");
                Platnerz3.WriteDescriptionOfSurroundings("Napisz \"kup-(numer przedmiotu z listy)\", aby kupić dany przedmiot.");
                Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Platnerz3.WriteItemList(text);
                Game.Move(text, Platnerz3.north, Platnerz3.east, Platnerz3.south, Platnerz3.west);
                if(text=="kup-1")
                    Geralt.BuyItem(Platnerz3.ReturnItem1());
                if(text=="kup-2")
                    Geralt.BuyItem(Platnerz3.ReturnItem2());
                if(text=="kup-3")
                    Geralt.BuyItem(Platnerz3.ReturnItem3());
                if(text=="kup-4")
                    Geralt.BuyItem(Platnerz3.ReturnItem4());
                if(text=="kup-5")
                    Geralt.BuyItem(Platnerz3.ReturnItem5());
                }
                continue;
            }
             //JASKINIA2
    Level Jaskinia2(106, "Jaskinia", "Stoisz w ciemnej grocie. Z podłogi ", "i sufitu wyłaniają się stalaktyty,", "stalagmity, i stalagnaty.", 55, 107, 0, 0);
        if(Game.ReturnCurrentID()==Jaskinia2.ReturnID())
            {
                Jaskinia2.WriteTitle();
                Jaskinia2.WriteDirections();
                Jaskinia2.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Jaskinia2.north, Jaskinia2.east, Jaskinia2.south, Jaskinia2.west);
            }
            continue;
        }

        //Jaskinia3
    Level Jaskinia3(107, "Jaskinia", "Stoisz w ciemnej grocie. Z podłogi ", "i sufitu wyłaniają się stalaktyty,", "stalagmity, i stalagnaty.", 108, 0, 0, 106);
        if(Game.ReturnCurrentID()==Jaskinia3.ReturnID())
            {
                Jaskinia3.WriteTitle();
                Jaskinia3.WriteDirections();
                Jaskinia3.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Jaskinia3.north, Jaskinia3.east, Jaskinia3.south, Jaskinia3.west);
            }
            continue;
        }

    //Jaskinia4
    Level Jaskinia4(108, "Jaskinia", "Stoisz w ciemnej grocie. Z podłogi ", "i sufitu wyłaniają się stalaktyty,", "stalagmity, i stalagnaty.", 109, 0, 107, 55);
        if(Game.ReturnCurrentID()==Jaskinia4.ReturnID())
            {
                Jaskinia4.WriteTitle();
                Jaskinia4.WriteDirections();
                Jaskinia4.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Jaskinia4.north, Jaskinia4.east, Jaskinia4.south, Jaskinia4.west);
            }
            continue;
        }

    //Jaskinia5
    Level Jaskinia5(109, "Jaskinia", "Stoisz w ciemnej grocie. Z podłogi ", "i sufitu wyłaniają się stalaktyty,", "stalagmity, i stalagnaty.", 0, 110, 108, 0);
        if(Game.ReturnCurrentID()==Jaskinia5.ReturnID())
            {
                Jaskinia5.WriteTitle();
                Jaskinia5.WriteDirections();
                Jaskinia5.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Jaskinia5.north, Jaskinia5.east, Jaskinia5.south, Jaskinia5.west);
            }
            continue;
        }

    //Jaskinia6
    Level Jaskinia6(110, "Jaskinia", "Stoisz w ciemnej grocie. Z podłogi ", "i sufitu wyłaniają się stalaktyty,", "stalagmity, i stalagnaty.", 0, 0, 0, 109);
        if(Game.ReturnCurrentID()==Jaskinia6.ReturnID())
            {
                Jaskinia6.WriteTitle();
                Jaskinia6.WriteDirections();
                Jaskinia6.WriteDescription();
               Game.LevelEnd=0;
                while (Game.LevelEnd==0)
                {
                Geralt.DrawHud();
                cin>>text;
                Game.Move(text, Jaskinia6.north, Jaskinia6.east, Jaskinia6.south, Jaskinia6.west);
            }
            continue;
        }




    }
   }
    if (MainMenu.nmenu()==2)
    {

    }
    if (MainMenu.nmenu()==3)
    {
    system("cls");

    cout<<endl;
    cout<<endl;

    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout<<"Nazwa: ";
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout<<"Witcher The Game"<<endl;

    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout<<"Wersja: ";
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout<<"1.0.0"<<endl;

    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout<<"Autor: ";
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout<<"Pawel Czernecki"<<endl;

    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout<<"Jezyk: ";
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout<<"C++"<<endl;

    SetConsoleTextAttribute( hOut, FOREGROUND_RED);
    cout<<endl<<endl<<"juniorcodeblog.wordpress.com"<<endl;

    }
    if (MainMenu.nmenu()==4)
    {}
    return 1;
}
