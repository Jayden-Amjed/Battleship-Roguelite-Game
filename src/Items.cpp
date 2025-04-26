#include "Items.h"
#include "Game.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <algorithm>
#include <functional>
using namespace std;




void Items::useHelicopterScout(vector<vector<pair<int,int>>> &shipPositions, vector<vector<string>> &board) {
    
    if (heliScout <= 0) {
        cout << "No Helicopter Scouts left!" << endl;
        return;
    }

    bool running = true;
    heliScout--; 
    while(running){
        running = false;

        mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

        // Random ship
        uniform_int_distribution<int> distShip(0, shipPositions.size() - 1);
        int randShip = distShip(gen);

        // Random part within the ship
        vector<pair<int,int>> &chosenShip = shipPositions[randShip];
        
        uniform_int_distribution<int> distPart(0, chosenShip.size() - 1);
        int randPart = distPart(gen);

        int row = chosenShip[randPart].first;
        int col = chosenShip[randPart].second;

        if (board[row][col] == "[X]"){
            running = true;
            continue; 
        }
        
        board[row][col] = "[S]"; // Reveal only one part
        cout << "Revealed positions: "<< row << "," << col << "\n";
        cout << "Press Enter to continue\n";


    }
}

void Items::useSonar(vector<vector<pair<int,int>>> &shipPositions, vector<vector<string>> &board) {
    if (sonar <= 0) {
        cout << "No Sonars Left!" << endl;
        return;
    }

    bool running = true;
    sonar--;
    while(running){
        
        running = false;
        mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<int> distShip(0, shipPositions.size() - 1);

        // Ensure all three ships revealed are different
        int randShip, randShip2, randShip3;
        do {
            randShip = distShip(gen);
            randShip2 = distShip(gen);
            randShip3 = distShip(gen);
        } while (randShip == randShip2 || randShip == randShip3 || randShip2 == randShip3);

        // Select ships
        vector<pair<int,int>> &chosenShip  = shipPositions[randShip];
        vector<pair<int,int>> &chosenShip2 = shipPositions[randShip2];
        vector<pair<int,int>> &chosenShip3 = shipPositions[randShip3];

        // Random parts
        uniform_int_distribution<int> distPart1(0, chosenShip.size() - 1);
        uniform_int_distribution<int> distPart2(0, chosenShip2.size() - 1);
        uniform_int_distribution<int> distPart3(0, chosenShip3.size() - 1);

        int randPart1 = distPart1(gen);
        int randPart2 = distPart2(gen);
        int randPart3 = distPart3(gen);

        // Get coordinates
        int row  = chosenShip[randPart1].first;
        int col  = chosenShip[randPart1].second;
        int row2 = chosenShip2[randPart2].first;
        int col2 = chosenShip2[randPart2].second;
        int row3 = chosenShip3[randPart3].first;
        int col3 = chosenShip3[randPart3].second;

        // Reveal if not already revealed
        if (board[row][col] == "[X]" || board[row2][col2] == "[X]" || board[row3][col3] == "[X]") {
            running = true;
            continue;
        }

        board[row][col]     = "[S]";
        board[row2][col2]   = "[S]";
        board[row3][col3]   = "[S]";
        cout << "Revealed positions: "<< row << "," << col << " | "<< row2 << "," << col2 << " | "<< row3 << "," << col3 << "\n";
        cout << "Press Enter to continue\n";
        }
    }


void Items::useBallisticMissile(vector<vector<pair<int,int>>> &shipPositions, vector<vector<string>> &board, Game &game) {

    if (ballisticMissle <= 0) {
        cout << "No Ballistic Missiles Scouts left!" << endl;
        return;
    }

    ballisticMissle--; // consume the item

    bool running = true;

    while(running) {
        cout << "Pick a postion to fire the super missle on: ('B6')\n";
        string userInput;
        
    
        if (cin.peek() == '\n') cin.ignore();  // flush leftover newline
        getline(cin,userInput);

        // Remove spaces if there is any
        userInput.erase(remove(userInput.begin(), userInput.end(), ' '), userInput.end());

        char col = toupper(userInput[0]); //If user input is lowercase number
        int row;
            
        try {
            row = stoi(userInput.substr(1)); //Converts the number part of the string to an int

        }catch (const invalid_argument& e) {
            cout << "Invalid input, try 'B5' or 'A10' Letter first" << endl;
            continue;
        
        }

        int userRow = row - 1; //convert back to 0 index
        int userColumn = toupper(col) - 'A'; //convert back to numbers

        // Board bounds check
        if (userRow < 0 || userRow >= board.size() || userColumn < 0 || userColumn >= board[0].size()) {
            cout << "Position out of bounds.\n";
            continue;
        }

        // Use a set to store all ship positions for fast lookup
        vector<pair<int, int>> shipCoords;
        for (const auto& ship : shipPositions) {
            for (const auto& part : ship) {
                shipCoords.push_back(part);
            }
        }


        missleCheck(board, game, 0, 0, userRow, userColumn, shipCoords); // Center
        missleCheck(board, game, 1, 0, userRow, userColumn, shipCoords); // Top
        missleCheck(board, game, 1, 1, userRow, userColumn, shipCoords); // Top-Right
        missleCheck(board, game, 1, -1, userRow, userColumn, shipCoords); // Top-Left
        missleCheck(board, game, 0, 1, userRow, userColumn, shipCoords); // Right
        missleCheck(board, game, 0, -1, userRow, userColumn, shipCoords); // Left
        missleCheck(board, game, -1, 0, userRow, userColumn, shipCoords); // Bottom
        missleCheck(board, game, -1, -1, userRow, userColumn, shipCoords); // Bottom-Left
        missleCheck(board, game, -1, 1, userRow, userColumn, shipCoords); // Bottom-Right

        
        
        cout << "Super Missle Used!\n Press Enter to continue\n";
        running = false;
    }
}

void Items::activateTorpedo(vector<vector<string>> &board, Game &game) {
    if (torpedo <= 0) {
        cout << "No Torpedos left!\n";
        return;
    }

    torpedo--; // consume the item
    int userRow;
    int userColumn;
    bool running = true;

    while(running) {
        cout << "Pick a postion to fire the super missle on: ('B6')\n";
        string userInput;
        
    
        if (cin.peek() == '\n') cin.ignore();  // flush leftover newline
        getline(cin,userInput);

        // Remove spaces if there is any
        userInput.erase(remove(userInput.begin(), userInput.end(), ' '), userInput.end());

        char col = toupper(userInput[0]); //If user input is lowercase number
        int row;
            
        try {
            row = stoi(userInput.substr(1)); //Converts the number part of the string to an int

        }catch (const invalid_argument& e) {
            cout << "Invalid input, try 'B5' or 'A10' Letter first" << endl;
            continue;
        
        }

        userRow = row - 1; //convert back to 0 index
        userColumn = toupper(col) - 'A'; //convert back to numbers

        // Board bounds check
        if (userRow < 0 || userRow >= board.size() || userColumn < 0 || userColumn >= board[0].size()) {
            cout << "Position out of bounds.\n";
            continue;
        }

        cout << "Torpedo launched! Press enter to continue.\n";
        running = false;
    }

    torpedoState.isOn = true;
    torpedoState.currentRow = userRow;
    torpedoState.column = userColumn;

}

void Items::updateTorpedo(vector<vector<pair<int,int>>> &shipPositions, vector<vector<string>> &board, Game &game) {    
    if (!torpedoState.isOn) return;

    //Get row and column
    int r = torpedoState.currentRow;
    int c = torpedoState.column;

    //If The torpedo reaches the top of the board then stop
    if (r < 0) {
        torpedoState.isOn = false;
        cout << "Torpedo has finished its sweep.\n";
        return;
    }

    for (int offset = -1; offset <= 1; ++offset) { //Colum offset to see to check the left (-1), center (0) and right (+1)
        int col = c + offset;
        //If column is out of bounds then skip
        if (col < 0 || col >= board[0].size()) continue;

        bool isHit = false;
        //Check if that column position had a ship part
        for (const auto& ship : shipPositions) {
            for (const auto& part : ship) {
                if (part.first == r && part.second == col) {
                    isHit = true;
                    break;
                }
            }
        }

        if (isHit) {
            if (board[r][col] != "[X]") {
                board[r][col] = "[X]";
                game.incrementHits();
            }
        } else {
            if (board[r][col] == "[ ]") {
                board[r][col] = "[O]";
            }
        }
    }

    torpedoState.currentRow--; // Move up one row for next turn
}



//Checks if SuperMissle hit or miss
void Items:: missleCheck(vector<vector<string>> &board, Game &game, int dr, int dc, int userRow, int userColumn,vector<pair<int, int>> &shipCoords){
    
    int r = userRow + dr;
    int c = userColumn + dc;

    // Check if position is in bounds
    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return;

    bool isHit = false;
    //Check if there is a hit
    for (const auto &pos : shipCoords) {
        if (r == pos.first && c == pos.second) {
            isHit = true; //Hit
            break;
        }
    }

    //Mark hit
    if (isHit) {
        if (board[r][c] != "[X]") {
            board[r][c] = "[X]";
            game.incrementHits();
        }
    } else {
        if (board[r][c] == "[ ]") {
            board[r][c] = "[O]";
        }
    }

}

