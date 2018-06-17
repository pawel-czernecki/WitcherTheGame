#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include <sstream>


using namespace std;

class GameSystem
{
private:
    int CurrentID;

public:
    bool LevelEnd;
    void ChangeCurrentID(int NextID);
    int ReadFile(int line);
    int ReturnCurrentID();
    void SaveFile(int isCharacterCreated, int hP, int maxhP, int aD, int coins, int exp, int id);
    void Move(string cmd, int N, int E, int S, int W);

    GameSystem()
    {
        CurrentID=1;

    }
};
