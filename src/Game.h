#ifndef GAME_H
#define GAME_H
#include <string>
#include <vector>
#include <random>

using namespace std;

class Game {
    private:
        int score = 0;
        int highscore = 0;
        int cash = 0;
        int shipParts = 0;
        int hitCount = 0;
        int missile = 15;
        int stageDifficulty = 0;


        
    

    public:
    
    void calculateShipParts(const vector<vector<string>> &board, const vector<vector<pair<int, int>>> &shipPositions);
    void setHighScore(int);
    void calculateCash(int);

    int resetMissile() {
        missile = 0;
    }

    int getStageDiff() const{
        return stageDifficulty;
    }

    int incrementStageDif() {
        stageDifficulty++;
    }

    //Getters
    int getScore() const {
        return score;
    }
    int getHighscore() const {
        return highscore;
    }

    int getCash() const {
        return cash;
    }

    int getShipParts() const {
        return shipParts;
    }
    
    int getHitCount() const {
        return hitCount;
    }

    int getMissile() const {
        return missile;
    }

    void setZero () {
        hitCount  = 0;
        shipParts = 0;
        score = 0;
    }

    void setScoreZero() {
        score = 0;
    }

    //Setters
    int addMissile (int add){
        missile += add;
    }

    int addScore (int add){
        score += add;
    }

    int addCash (int add){
        cash += add;
    }

    int subCash (int sub){
        cash -= sub;
    }

    //Basic Functions
    int deccrementMissile () {
        missile--;
    }

    int incrementHits() {
        hitCount++;
    }

    

};

#endif