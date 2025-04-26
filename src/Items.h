#ifndef ITEMS_H
#define ITEMS_H
#include <string>
#include <vector>
#include <random>

using namespace std;
struct Torpedo{
    bool isOn = false;
    int currentRow = 0;
    int column = 0;
};

class Game;

class Items {
    private:
    int heliScout = 0;
    int sonar = 0;
    int ballisticMissle = 0;
    int torpedo = 0;

    public:
    void updateTorpedo(vector<vector<pair<int,int>>> &, vector<vector<string>> &, Game &);
    void activateTorpedo(vector<vector<string>> &,Game &);
    void useHelicopterScout(vector<vector<pair<int,int>>> &, vector<vector<string>> &);
    void useSonar(vector<vector<pair<int,int>>> &, vector<vector<string>> &);
    void useBallisticMissile(vector<vector<pair<int,int>>> &, vector<vector<string>> &, Game &);
    void missleCheck(vector<vector<string>> &, Game &, int, int, int, int, vector<pair<int, int>> &);

    Torpedo torpedoState;

    //Adds
    int addTorpedo(int add){
        torpedo += add;
    }

    int addSonar(int add){
        sonar += add;
    }

    int addHeliScout(int add) {
        heliScout += add;
    }

    int addSuperMissile(int add) {
        ballisticMissle += add;
    }



    //Getters
    int getHeliScout() const{
        return heliScout;
    }

    int getSonar() const{
        return sonar;
    }

    int getBallisticMissile() const{
        return ballisticMissle;
    }

    int getTorpedo() const{
        return torpedo;
    }

    //Increments
    void incHeliScout() {
        heliScout++;
    }

    void incSonar() {
        sonar++;
    }
    void incSuperMissile() {
        ballisticMissle++;
    }
    void incTorpedo() {
        torpedo++;
    }

    //Decrements
    void decHeliScout() {
        heliScout--;
    }

    void decSonar() {
        sonar--;
    }
    void decSuperMissile() {
        ballisticMissle--;
    }
    void decTorpedo() {
        torpedo--;
    }
  
  


};


#endif