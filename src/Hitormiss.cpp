#include "Hitormiss.h"
#include "Game.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;


//Get board as reference,
//Get user input
//Check if user input is == to a valid ship postion
// If valid, replace position with [X]
// if invalid, replace postion with [O]
// print the new


void Hitormiss:: checkHit(vector<vector<string>> &board, vector<vector<pair<int,int>>> &shipPositions, int r, char c, Game &game, int &combo, vector<pair<int,int>> &userInputs ){
    int userRow = r - 1; //convert back to 0 index
    int userCol = toupper(c) - 'A'; //convert back to numbers
    int comboCount;


    if ((userRow < 0 || userRow >= board.size()) || (userCol < 0 || userCol >= board[0].size())){
        cout << setw(125) << "----------Invalid input, try again!---------" << endl;
        return;
    }
    
    //check if position has already been hit
    for (const auto& pos: userInputs){
        if (userRow == pos.first && userCol == pos.second ){
            cout << setw(129) << "------- This position has already been hit!-------" << endl;
            return;
        }
    }
    //Add position to a vector to store it for comparison
    userInputs.push_back({userRow,userCol});
    
    
    //Hit check
    for( int i = 0; i < shipPositions.size(); i++){ //Loops through shipositions
        for (const auto& pos : shipPositions[i]){ //Takes positions
            int row = pos.first;
            int col = pos.second;

            if (userRow == row && userCol == col){
                combo++;
                userInputs.push_back({userRow,userCol});

                cout << setw(123) << " _     _    _____    _____    _ " <<endl;
                cout << setw(123) << "| |___| |  |_   _|  |_   _|  | |" <<endl;
                cout << setw(123) << "|  ___  |    | |      | |    | |" <<endl;
                cout << setw(123) << "| |   | |   _| |_     | |    |_|" <<endl;
                cout << setw(123) << "|_|   |_|  |_____|    |_|     + " <<endl;
                
                //Combos
                if (combo == 1){
                    cout << setw(126) << "(\033[38;5;44m+100 Points\033[0m)" << endl;
                    game.addScore(100);
                } else if (combo == 2){
                    cout << setw(140) << "(\033[31m2X Combo\033[0m: \033[38;5;44m+120 Points\033[0m)" << endl;
                    game.addScore(120);
                } else if (combo == 3){
                    cout << setw(189) << "(\033[31m3X Combo\033[0m: \033[38;2;255;105;180m+2 Missiles\033[0m & \033[38;5;220m+60 cash\033[0m & \033[38;5;44m+140 points\033[0m)" << endl;
                    game.addScore(140);
                    game.addMissile(2);
                    game.addCash(60);
                } else if (combo == 4){
                    cout << setw(162) << "(\033[31m4X Combo\033[0m: \033[38;5;220m+100 cash\033[0m & \033[38;5;44m+160 points\033[0m)" << endl;
                    game.addScore(160);
                    game.addCash(100);
                } else if (combo == 5){
                    cout << setw(191) << "(\033[31m5X Combo\033[0m: \033[38;2;255;105;180m+2 Missiles\033[0m & \033[38;5;220m+120 cash\033[0m & \033[38;5;44m+180 points\033[0m)" << endl;
                    game.addScore(180);
                    game.addMissile(2);
                    game.addCash(120);
                } else if (combo > 5){
                    string txtCombo = to_string(combo);
                    
                    cout << setw(91) << "(\033[31m" << txtCombo << "X Combo\033[0m: \033[38;2;255;105;180m+1 Missles & \033[38;5;220m+150 cash\033[0m & \033[38;5;44m+200 points\033[0m)" << endl;
                    game.addScore(200);
                    game.addMissile(1);
                    game.addCash(150);
                }
                
                //Increment Hits and Mark X
                cout <<endl;
                cout <<endl;
                game.incrementHits();
                board[userRow][userCol] = "[X]";


                return;
            }
        }    
    }           
    
    //Miss
    cout << setw(130) << " _________    _____    _____    _____    _ "<<endl;
    cout << setw(130) << "|  _   _  |  |_   _|  |  ___|  |  ___|  | |" <<endl;
    cout << setw(130) << "| | |_| | |    | |    |___  |  |___  |  | |"<<endl;
    cout << setw(130) << "| |     | |   _| |_    ___| |   ___| |  |_|"<<endl;
    cout << setw(130) << "|_|     |_|  |_____|  |_____|  |_____|   + "<<endl;
    cout <<endl;
    cout <<endl;
    
    //Reset Combo and decrement missles and mark O
    combo = 0;
    game.deccrementMissile();
    board[userRow][userCol] = "[O]";
        
       
      
}

