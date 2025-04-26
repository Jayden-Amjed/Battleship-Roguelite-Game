#include "Game.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;


//Sets ship part number then compares that how many X's are on board
void Game::calculateShipParts(const vector<vector<string>> &board, const vector<vector<pair<int, int>>> &shipPositions) {
    
    for (const auto &ship : shipPositions) {
        shipParts += ship.size();
    }
    
}

void Game::setHighScore(int currentScore){
    if (currentScore > highscore){
        highscore = currentScore;
    }  
}

void Game::calculateCash(int currentScore){
    int add = currentScore/10;
    cash += add;
}