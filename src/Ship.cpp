#include "Ship.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>

using namespace std;

Ship::Ship() : gen(chrono::steady_clock::now().time_since_epoch().count()) {} //Get random number

vector<pair<int,int>> Ship::addAircc(vector<vector<string>> &board, int row, int col){
    
    bool isValid = false; // Flag
    uniform_int_distribution<int> distR(0, row - 1); // Range of row
    uniform_int_distribution<int> distC(0, col - 1); // Range of column
    uniform_int_distribution<int> distD(0, 3); // Range of direction
    vector<pair<int, int>> positions;  //  Pair Vector to store all of ship positions

    while (!isValid) { 
        //cout << "Running While loop for Aircraft Carrier" << endl;


        int rdR = distR(gen); // Random row
        int rdC = distC(gen); // Random column
        int rdD = distD(gen); // Random direction

        //Check if ship can be placed in chosen direction
        bool canPlace = true;
        positions.clear();
        positions.push_back({rdR, rdC}); // Initial head position

       
        if (board[rdR][rdC] != "[ ]"){
            canPlace = false;
        } else if (rdD == 0) { // Up direction
            for (int i = 1; i < AIRCRAFT_CARRIER; i++) {
                int newC = rdC + i;
                if (newC >= col || board[rdR][newC] != "[ ]") { //if board position is already occupied, turn off flag
                    canPlace = false;
                    break;
                }
                positions.push_back({rdR, newC}); //Store tail position
            }
        } else if (rdD == 1) { // Right direction
            for (int i = 1; i < AIRCRAFT_CARRIER; i++) {
                int newR = rdR + i;
                if (newR >= row || board[newR][rdC] != "[ ]") {

                    canPlace = false;
                    break;
                }
                positions.push_back({newR, rdC});
            }
        } else if (rdD == 2) { // Left direction
            for (int i = 1; i < AIRCRAFT_CARRIER; i++) {
                int newC = rdC - i;
                if (newC < 0 || board[rdR][newC] != "[ ]") {

                    canPlace = false;
                    break;
                }
                positions.push_back({rdR, newC});
            }
        } else if (rdD == 3) { // Down direction
            for (int i = 1; i < AIRCRAFT_CARRIER; i++) {
                int newR = rdR - i;
                if (newR < 0 || board[newR][rdC] != "[ ]") {

                    canPlace = false;
                    break;
                }
                positions.push_back({newR, rdC});
            }
        }


        if (canPlace) { //If all positions were valid then we can display them
            for (int i = 0; i < positions.size(); i ++){
                int row = positions[i].first;
                int col = positions[i].second;
    
                board[row][col] = "[A]";
           }
           isValid = true; // Can exit loop
        }
    }
    return positions;
}




vector<pair<int,int>> Ship::addBattleship(vector<vector<string>> &board, int row, int col){
    
    bool isValid = false; // Flag
    uniform_int_distribution<int> distR(0, row - 1); // Range of row
    uniform_int_distribution<int> distC(0, col - 1); // Range of column
    uniform_int_distribution<int> distD(0, 3); // Range of direction
    vector<pair<int, int>> positions;  //  Pair Vector to store all of ship positions

    while (!isValid) { 
        //cout << "Running While loop for Battleship" << endl;

        int rdR = distR(gen); // Random row
        int rdC = distC(gen); // Random column
        int rdD = distD(gen); // Random direction


        //Check if ship can be placed in chosen direction
        bool canPlace = true;
        positions.clear();
        positions.push_back({rdR, rdC}); // Initial head position

       
        if (board[rdR][rdC] != "[ ]"){
            canPlace = false;
        } else if (rdD == 0) { // Up direction
            for (int i = 1; i < BATTLESHIP; i++) {
                int newC = rdC + i;
                if (newC >= col || board[rdR][newC] != "[ ]") { //if board position is already occupied, turn off flag

                    canPlace = false;
                    break;
                }
                positions.push_back({rdR, newC}); //Store tail position
            }
        } else if (rdD == 1) { // Right direction
            for (int i = 1; i < BATTLESHIP; i++) {
                int newR = rdR + i;
                if (newR >= row || board[newR][rdC] != "[ ]") {

                    canPlace = false;
                    break;
                }
                positions.push_back({newR, rdC});
            }
        } else if (rdD == 2) { // Left direction
            for (int i = 1; i < BATTLESHIP; i++) {
                int newC = rdC - i;
                if (newC < 0 || board[rdR][newC] != "[ ]") {

                    canPlace = false;
                    break;
                }
                positions.push_back({rdR, newC});
            }
        } else if (rdD == 3) { // Down direction
            for (int i = 1; i < BATTLESHIP; i++) {
                int newR = rdR - i;
                if (newR < 0 || board[newR][rdC] != "[ ]") {

                    canPlace = false;
                    break;
                }
                positions.push_back({newR, rdC});
            }
        }
      
        if (canPlace) { //If all positions were valid then we can display them
            for (int i = 0; i < positions.size(); i ++){
                int row = positions[i].first;
                int col = positions[i].second;
    
                board[row][col] = "[B]";
           }
           isValid = true; // Can exit loop
        }
    }
    return positions;
}

vector<pair<int,int>> Ship::addDestroyer(vector<vector<string>> &board, int row, int col){
    
    bool isValid = false; // Flag
    uniform_int_distribution<int> distR(0, row - 1); // Range of row
    uniform_int_distribution<int> distC(0, col - 1); // Range of column
    uniform_int_distribution<int> distD(0, 3); // Range of direction
    vector<pair<int, int>> positions;  //  Pair Vector to store all of ship positions

    while (!isValid) { 
        //cout << "Running While loop for Destroyer" << endl;

        int rdR = distR(gen); // Random row
        int rdC = distC(gen); // Random column
        int rdD = distD(gen); // Random direction


        //Check if ship can be placed in chosen direction
        bool canPlace = true;
        positions.clear();
        positions.push_back({rdR, rdC}); // Initial head position
        
        
        if (board[rdR][rdC] != "[ ]"){
            canPlace = false;
        } else if (rdD == 0) { // Up direction
            for (int i = 1; i < DESTROYER; i++) {
                int newC = rdC + i;
                if (newC >= col || board[rdR][newC] != "[ ]") { //if board position is already occupied, turn off flag

                    canPlace = false;
                    break;
                }
                positions.push_back({rdR, newC}); //Store tail position
            }
        } else if (rdD == 1) { // Right direction
            for (int i = 1; i < DESTROYER; i++) {
                int newR = rdR + i;
                if (newR >= row || board[newR][rdC] != "[ ]") {

                    canPlace = false;
                    break;
                }
                positions.push_back({newR, rdC});
            }
        } else if (rdD == 2) { // Left direction
            for (int i = 1; i < DESTROYER; i++) {
                int newC = rdC - i;
                if (newC < 0 || board[rdR][newC] != "[ ]") {

                    canPlace = false;
                    break;
                }
                positions.push_back({rdR, newC});
            }
        } else if (rdD == 3) { // Down direction
            for (int i = 1; i < DESTROYER; i++) {
                int newR = rdR - i;
                if (newR < 0 || board[newR][rdC] != "[ ]") {

                    canPlace = false;
                    break;
                }
                positions.push_back({newR, rdC});
            }
        }

        if (canPlace) { //If all positions were valid then we can display them
            for (int i = 0; i < positions.size(); i ++){
                int row = positions[i].first;
                int col = positions[i].second;
    
                board[row][col] = "[D]";
           }
           isValid = true; // Can exit loop
        }
    }
    return positions;
}

vector<pair<int,int>> Ship::addSub(vector<vector<string>> &board, int row, int col) {
    
    bool isValid = false; // Flag
    uniform_int_distribution<int> distR(0, row - 1); // Range of row
    uniform_int_distribution<int> distC(0, col - 1); // Range of column
    uniform_int_distribution<int> distD(0, 3); // Range of direction
    vector<pair<int, int>> positions;  //  Pair Vector to store all of ship positions

    while (!isValid) { 
        //cout << "Running While loop for Sub" << endl;

        int rdR = distR(gen); // Random row
        int rdC = distC(gen); // Random column
        int rdD = distD(gen); // Random direction


        //Check if ship can be placed in chosen direction
        bool canPlace = true;
        positions.clear();
        positions.push_back({rdR, rdC}); // Initial head position
        
        
        if (board[rdR][rdC] != "[ ]"){
            canPlace = false;
        } else if (rdD == 0) { // Up direction
            for (int i = 1; i < SUB; i++) {
                int newC = rdC + i;
                if (newC >= col || board[rdR][newC] != "[ ]") { //if board position is already occupied, turn off flag
                    canPlace = false;
                    break;
                }
                positions.push_back({rdR, newC}); //Store tail position
            }
        } else if (rdD == 1) { // Right direction
            for (int i = 1; i < SUB; i++) {
                int newR = rdR + i;
                if (newR >= row || board[newR][rdC] != "[ ]") {

                    canPlace = false;
                    break;
                }
                positions.push_back({newR, rdC});
            }
        } else if (rdD == 2) { // Left direction
            for (int i = 1; i < SUB; i++) {
                int newC = rdC - i;
                if (newC < 0 || board[rdR][newC] != "[ ]") {

                    canPlace = false;
                    break;
                }
                positions.push_back({rdR, newC});
            }
        } else if (rdD == 3) { // Down direction
            for (int i = 1; i < SUB; i++) {
                int newR = rdR - i;
                if (newR < 0 || board[newR][rdC] != "[ ]") {

                    canPlace = false;
                    break;
                }
                positions.push_back({newR, rdC});
            }
        }

      
        if (canPlace) { //If all positions were valid then we can display them
            for (int i = 0; i < positions.size(); i ++){
                int row = positions[i].first;
                int col = positions[i].second;
    
                board[row][col] = "[S]";
           }
           isValid = true; // Can exit loop
        }
    }
    return positions;
}


vector<pair<int,int>> Ship::addFrigate(vector<vector<string>> &board, int row, int col){
    
    bool isValid = false; // Flag
    uniform_int_distribution<int> distR(0, row - 1); // Range of row
    uniform_int_distribution<int> distC(0, col - 1); // Range of column
    uniform_int_distribution<int> distD(0, 3); // Range of direction
    vector<pair<int, int>> positions;  //  Pair Vector to store all of ship positions
    while (!isValid) { 
        //cout << "Running While loop for Frigate" << endl;

        int rdR = distR(gen); // Random row
        int rdC = distC(gen); // Random column
        int rdD = distD(gen); // Random direction


        //Check if ship can be placed in chosen direction
        bool canPlace = true;
        positions.clear();
        positions.push_back({rdR, rdC}); // Initial head position


        if (board[rdR][rdC] != "[ ]"){
            canPlace = false;
        } else if (rdD == 0) { // Up direction
            for (int i = 1; i < FRIGATE; i++) {
                int newC = rdC + i;
                if (newC >= col || board[rdR][newC] != "[ ]") { //if board position is already occupied, turn off flag
                    canPlace = false;
                    break;
                }
                positions.push_back({rdR, newC}); //Store tail position
            }
        } else if (rdD == 1) { // Right direction
            for (int i = 1; i < FRIGATE; i++) {
                int newR = rdR + i;
                if (newR >= row || board[newR][rdC] != "[ ]") {

                    canPlace = false;
                    break;
                }
                positions.push_back({newR, rdC});
            }
        } else if (rdD == 2) { // Left direction
            for (int i = 1; i < FRIGATE; i++) {
                int newC = rdC - i;
                if (newC < 0 || board[rdR][newC] != "[ ]") {

                    canPlace = false;
                    break;
                }
                positions.push_back({rdR, newC});
            }
        } else if (rdD == 3) { // Down direction
            for (int i = 1; i < FRIGATE; i++) {
                int newR = rdR - i;
                if (newR < 0 || board[newR][rdC] != "[ ]") {
                    canPlace = false;
                    break;
                }
                positions.push_back({newR, rdC});
            }
        }
      
        if (canPlace) { //If all positions were valid then we can display them
            for (int i = 0; i < positions.size(); i ++){
                int row = positions[i].first;
                int col = positions[i].second;
    
                board[row][col] = "[F]";
           }
           isValid = true; // Can exit loop
        }
    }
    return positions;
}









//Get random index
//Get random direction to lay ship
//Check if its valid spot to put ship
//If not repeat
