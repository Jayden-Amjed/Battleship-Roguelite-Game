#ifndef HITORMISS_H
#define HITORMISS_H

#include <string>
#include <vector>
using namespace std;

class Game;

class Hitormiss {
    private:
    
    public:
    void checkHit(vector<vector<string>> &, vector<vector<pair<int,int>>> &, int , char, Game &, int &, vector<pair<int,int>> & ); //Reference of board, row and column inputs

        
};


#endif