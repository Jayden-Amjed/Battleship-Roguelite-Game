#ifndef SHIP_H
#define SHIP_H
#include <string>
#include <vector>
#include <random>

using namespace std;

class Ship {
    private:
    const int FRIGATE = 2;
    const int SUB = 3;
    const int DESTROYER = 3;
    const int BATTLESHIP = 4;
    const int AIRCRAFT_CARRIER = 5;

    mt19937 gen; //rng generator

    public:
        Ship();
        vector<pair<int,int>> addFrigate(vector<vector<string>> &, int, int);
        vector<pair<int,int>> addSub(vector<vector<string>>&, int, int);
        vector<pair<int,int>> addDestroyer(vector<vector<string>>&, int, int);
        vector<pair<int,int>> addBattleship(vector<vector<string>>&, int, int);
        vector<pair<int,int>> addAircc(vector<vector<string>>&, int, int);
        void addAll(vector<vector<string>>&, int, int);


};

#endif