#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>
using namespace std;

class Board {
    private:
        int col = 0;
        int row = 0;
        vector<vector<string>> board;
      
    public:
        Board(int r , int c); //Constructor
        
        int getColumns() const{
            return col;
        };
        int getRows() const {
            return row;
        };
        vector<vector<string>> getBoard() const {
            return board;
        };
        
};


#endif