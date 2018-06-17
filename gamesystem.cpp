#include "gamesystem.h"

void GameSystem::ChangeCurrentID(int NextID)
{
    GameSystem::CurrentID=NextID;
}

int GameSystem::ReturnCurrentID()
{
    return GameSystem::CurrentID;
}

int GameSystem::ReadFile(int line)
{
    /*fstream save;
    string napis;
    save.open( "stats.txt", ios::in );
    int tab[8];
    if(save.good())
    {
        for(int i=1; i>=8; i++)
        {
            getline(save, napis);
            istringstream iss(napis);
            iss >> tab[i];
        }
        save.close();
    }else cout<<"Nie udało się odnaleść pliku"<<endl;
    cout<<tab[1];
    return tab[line];*/
    int tab[8];
    ifstream save( "stats.txt" );
    save >> tab[1] >> tab[2] >> tab[3] >> tab[4] >> tab[5] >> tab[6] >> tab[7];
    return tab[line];
}

void GameSystem::SaveFile(int isCharacterCreated, int hP,int maxhP, int aD, int coins, int exp, int id)
{
    ofstream out( "stats.txt" );
    out << isCharacterCreated << " " << hP << " " << maxhP << " " << aD <<  " " << coins <<  " " << exp << " " << id << std::endl;
    out.close();
}

void GameSystem::Move(string cmd, int N, int E, int S, int W)
{
         if ((cmd=="n")||(cmd=="north"))
                    {
                        if(N!=0)
                        {GameSystem::ChangeCurrentID(N);
                        GameSystem::LevelEnd=1;}
                        else cout<<"Nie możesz tam iść!"<<endl;
                    }
                if ((cmd=="e")||(cmd=="east"))
                    {
                        if(E!=0)
                        {GameSystem::ChangeCurrentID(E);
                        GameSystem::LevelEnd=1;}
                        else cout<<"Nie możesz tam iść!"<<endl;
                    }
                if ((cmd=="s")||(cmd=="south"))
                    {
                        if(S!=0)
                        {GameSystem::ChangeCurrentID(S);
                        GameSystem::LevelEnd=1;}
                        else cout<<"Nie możesz tam iść!"<<endl;
                    }
                if ((cmd=="w")||(cmd=="west"))
                    {
                        if(W!=0)
                        {GameSystem::ChangeCurrentID(W);
                        GameSystem::LevelEnd=1;}
                        else cout<<"Nie możesz tam iść!"<<endl;
                    }
}
