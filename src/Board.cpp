#include "Board.h"
#include <string>
#include <vector>
using namespace std;

//Constructor: Takes rows and columns and makes a board
Board::Board(int r, int c) {
    row = r;
    col = c;
    
    vector<vector<string>> matrix(row,vector<string>(col,"[ ]")); //In each row, there is a vector of n columns
    board = matrix;

}




//Create the board
//Get the board back to manipulate it
///* "args": [
    //main.cpp",
    //"Board.cpp",
    //"Ship.cpp",
    //"-o",
    //"main"