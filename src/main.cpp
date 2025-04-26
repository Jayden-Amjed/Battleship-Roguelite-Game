#include <iostream>
#include "Board.h"
#include "Ship.h"
#include "Hitormiss.h"
#include "Game.h"
#include "Items.h"
#include <algorithm>
#include <iomanip>
#include <chrono>
#include <functional>
using namespace std;

//Function prototypes

void displayBoard(vector<vector<string>> &, int, int, int);
void clearScreen();
void mainMenu();
void startGame(Game &,Items &);
void revealShips(vector<vector<pair<int,int>>> &, vector<vector<string>> & );
void soldierAnimation();


//main
int main(){
    soldierAnimation();
    mainMenu();

	return 0;
}

//Shop menu function
void shopMenu(Game &game,Items &items){

    //Get cash value to use across menu
    string cash = to_string(game.getCash());

    //Print menu
    cout << "=========== WAREHOUSE =========="  << left << setw(15) << "=" << "(\033[38;2;60;179;113mBank: $" << cash << "\033[0m)\n";
    cout << "1. Ballistic Missile: (\033[38;2;60;179;113m$350\033[0m)\n";
    cout << "   - A missile that covers a 3x3 area\n";
    cout << "2. Helicopter Scout: (\033[38;2;60;179;113m$200\033[0m)\n";
    cout << "   -Randomly shows 1 ship part location on the battlefield.\n";
    cout << "3. Missiles: (\033[38;2;60;179;113m$100\033[0m)\n";
    cout << "   -Extra regular missile.\n";
    cout << "4. Sonar: (\033[38;2;60;179;113m$400\033[0m)\n";
    cout << "   -Randomly shows 3 ship parts location on the battlefield.\n";
    cout << "5. Torpedo: (\033[38;2;60;179;113m$500\033[0m)\n";
    cout << "   -Moves through the board after every turn, covering a 1x3 area.\n";
    cout << "6. Nuke: (\033[38;2;60;179;113m$1500\033[0m)\n";
    cout << "   -Destroys the battlefield and everything with in it.\n";
    cout << "7. Exit\n";
    cout << "Choose an option: ";
    

    //Get menu choice
    int choice;
    cin >> choice;
    cin.ignore(); // flush newline from input


    switch (choice) {
        
        //Ballistic missile purchase
        case 1: {
            clearScreen();
            bool flag = true;

            while (flag) {
                string cash = to_string(game.getCash());
                flag = false;

                cout << "Ballistic Missile: A missile that explodes a 3x3 area" << left << setw(15) << "." 
                    << "(\033[38;2;60;179;113mBank: $" << cash << "\033[0m)" << endl;

                cout << "Enter the amount of Ballistic Missiles you'd like to purchase or press Enter to return:\n";
                cout << "Amount: ";
                
                // Get amount
                string amount;
                int intAmount;
                getline(cin, amount);

                if (amount.empty()) {
                    break; // return to shop menu
                }

                try {
                    intAmount = stoi(amount);
                } catch (...) {
                    clearScreen();
                    flag = true;
                    cout << "Invalid input! Please enter a number.\nPress Enter to try again.\n";
                    cin.ignore();
                    continue;
                }

                int cost = intAmount * 350;

                if (cost > game.getCash()) {
                    clearScreen();
                    flag = true;
                    cout << "Insufficient Funds!\nPress Enter to try again.\n";
                    cin.ignore();
                    continue;
                }

                // Successful purchase
                items.addSuperMissile(intAmount);
                game.subCash(cost);

                cout << intAmount << " Ballistic Missile(s) Purchased for \033[38;2;60;179;113m$" << to_string(cost) << "\033[0m!\n";
                cout << "Press Enter to return to the shop menu.\n";
                cin.ignore();
                break;
        }
            break;
        } case 2: { // Buying Helicopter Scout
            clearScreen();
            bool flag = true;
                
                while (flag) {
                    string cash = to_string(game.getCash());
                    flag = false;
                    
                    cout << "Helicopter Scout: Reveals a random ship part on the battlefield" << left << setw(15) << "." << "(\033[38;2;60;179;113mBank: $" << cash << "\033[0m)" << endl;
                    cout << "Enter the amount of Helicopter Scouts you'd like to purchase or Enter to return\n";
                    cout << "Amount: ";
                    
                    // Get amount
                    string amount;
                    int intAmount;
                    getline(cin, amount);

                    if (amount.empty()) {
                        break; // return to shop menu
                    }
                    
                    try {
                        intAmount = stoi(amount);
                    } catch (...) {
                        clearScreen();
                        flag = true;
                        cout << "Invalid input! Please enter a number.\nPress Enter to try again.\n";
                        cin.ignore();
                        continue;
                    }
                    
                    //Updates player money
                    int cost = intAmount * 200;

                    if (cost > game.getCash()){
                        clearScreen(); 
                        flag = true;
                        cout << "Insufficent Funds!\nPress Enter to return\n";

                        cin.ignore();
                        continue;
                        
                    }

                    items.addHeliScout(intAmount);
                    game.subCash(cost);
                    
                    cout << intAmount << " Helicopter Scout(s) Purchased for \033[38;2;60;179;113m$" << to_string(cost) << "\033[0m!\n";
                    cout <<"Press Enter to return to the shop menu.\n";
                    cin.ignore();
                    break;
           
                }
            break;

        }case 3: { //Buying Missles
            clearScreen();
            bool flag = true;
                
            while (flag) {
                    
                string cash = to_string(game.getCash());
                    flag = false;
                    
                    cout << "Missiles: Buy extra missiles to start the game with" << left << setw(15) << "." << "(\033[38;2;60;179;113mBank: $" << cash << "\033[0m)" << endl;
                    cout << "Enter amount of missiles you'd like to purchase or Enter to return\n";
                    cout << "Amount: ";
                    
                    // Get amount
                    string amount;
                    int intAmount;
                    getline(cin, amount);

                    if (amount.empty()) {
                        break; // return to shop menu
                    }
                    
                    try {
                        intAmount = stoi(amount);
                    } catch (...) {
                        clearScreen();
                        flag = true;
                        cout << "Invalid input! Please enter a number.\nPress Enter to try again.\n";
                        cin.ignore();
                        continue;
                    }
                    
                    //Updates player money
                    int cost = intAmount * 100;

                    if (cost > game.getCash()){
                        

                        clearScreen(); 
                        flag = true;
                        cout << "Insufficent Funds!\nPress Enter to return\n";

                        cin.ignore();
                        continue;
                        
                    }

                    game.addMissile(intAmount);
                    game.subCash(cost);
                    
                    cout << intAmount << " Missiles Purchased for \033[38;2;60;179;113m$" << to_string(cost) << "\033[0m!\n";
                    cout <<"Press Enter to return to the shop menu.\n";
                    cin.ignore();
                    break;
           
                }
        
            break;

        } case 4:{ //Sonar
            clearScreen();
            bool flag = true;
                
                while (flag) {
                    string cash = to_string(game.getCash());
                    flag = false; 
                    
                    cout << "Sonar: Reveal 3 random ship positions" << left << setw(15) << "." << "(\033[38;2;60;179;113mBank: $" << cash << "\033[0m)" << endl;
                    cout << "Enter the amount of Sonars you'd like to purchase or Enter to return\n";
                    cout << "Amount: ";
                    // Get amount
                    string amount;
                    int intAmount;
                    getline(cin, amount);

                    if (amount.empty()) {
                        break; // return to shop menu
                    }
                    
                    try {
                        intAmount = stoi(amount);
                    } catch (...) {
                        clearScreen();
                        flag = true;
                        cout << "Invalid input! Please enter a number.\nPress Enter to try again.\n";
                        cin.ignore();
                        continue;
                    }
                    
                    //Updates player money
                    int cost = intAmount * 400;

                    if (cost > game.getCash()){
                        clearScreen(); 
                        flag = true;
                        cout << "Insufficent Funds!\nPress Enter to return\n";

                        cin.ignore();
                        continue;
                        
                    }

                    items.addSonar(intAmount);
                    game.subCash(cost);
                    
                    cout << intAmount << " Sonar(s) Purchased for \033[38;2;60;179;113m$" << to_string(cost) << "\033[0m!\n";
                    cout <<"Press Enter to return to the shop menu.\n";
                    cin.ignore();
                    break;
           
                }
            break;
        
        } case 5:{ //Torpedo
            clearScreen();
            bool flag = true;
                
                while (flag) {
                    string cash = to_string(game.getCash());
                    flag = false; 
                    
                    cout << "Torpedo: Sweep a 3x1 area across the board, only updates after every turn." << left << setw(15) << "." << "(\033[38;2;60;179;113mBank: $" << cash << "\033[0m)" << endl;
                    cout << "Enter the amount of Torpedos you'd like to purchase or Enter to return\n";
                    cout << "Amount: ";
                    // Get amount
                    string amount;
                    int intAmount;
                    getline(cin, amount);

                    if (amount.empty()) {
                        break; // return to shop menu
                    }
                    
                    try {
                        intAmount = stoi(amount);
                    } catch (...) {
                        clearScreen();
                        flag = true;
                        cout << "Invalid input! Please enter a number.\nPress Enter to try again.\n";
                        cin.ignore();
                        continue;
                    }
                    
                    //Updates player money
                    int cost = intAmount * 500;

                    if (cost > game.getCash()){
                        clearScreen(); 
                        flag = true;
                        cout << "Insufficent Funds!\nPress Enter to return\n";

                        cin.ignore();
                        continue;
                        
                    }

                    items.addTorpedo(intAmount);
                    game.subCash(cost);
                    
                    cout << intAmount << " Torpedo(s) Purchased for \033[38;2;60;179;113m$" << to_string(cost) << "\033[0m!\n";
                    cout <<"Press Enter to return to the shop menu.\n";
                    cin.ignore();
                    break;
           
                }
            break;
            

        } case 6: {

        }
            cout << "Invalid option.\n";
    }
}




void startGame(Game &game,Items &items){
    
    vector<pair<int,int>> userInputs; //Store registered hits
    int combo = 0; //make combo counter
    game.setZero(); //makes ship parts and hit count 0 at every new game
    
    //Create hit or miss, set board size, get board
    Hitormiss hitormiss;
    int boardSize = 10 + game.getStageDiff();
    Board board(boardSize,boardSize); // Make board size
    Ship ship; 
    int rows = board.getRows();
    int cols = board.getColumns();
    vector<vector<string>>test = board.getBoard(); //Get board 
    
    //Vector with all ship functions call using shipfunc[i]()
    vector<function<vector<pair<int,int>>()>> shipFunc;
    shipFunc.push_back([&]() { return ship.addFrigate(test,rows,cols); });
    shipFunc.push_back([&]() { return ship.addAircc(test,rows,cols); });
    shipFunc.push_back([&]() { return ship.addDestroyer(test,rows,cols); });
    shipFunc.push_back([&]() { return ship.addBattleship(test,rows,cols); });
    shipFunc.push_back([&]() { return ship.addSub(test,rows,cols); });

    //Vector to store ship positions
    vector<vector<pair<int,int>>>shipPositions;
    for (int i = 0; i < shipFunc.size(); i++){
        shipPositions.push_back(shipFunc[i]());
    }

    //Position debug
    //cout << "==== DEBUG: SHIP POSITIONS ====" << endl;
        //for (int i = 0; i < shipPositions.size(); ++i) {
            //for (const auto& part : shipPositions[i]) {
            //cout << "Ship " << i + 1 << " part at (Row: " << part.first + 1 << ", Col: " << char('A' + part.second) << ")" << endl;
        //}
    //}

    //Hide Ships
    for (int r = 0; r < test.size(); ++r) {
        for (int c = 0; c < test[0].size(); ++c) {
            if (test[r][c] != "[X]" && test[r][c] != "[ ]") {
                test[r][c] = "[ ]";  // hide ship markers
            }
        }
    }
    

    //Randomly generate a new ship to add
    if (game.getStageDiff() > 1) {
        mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<int> distShip(0, shipFunc.size() - 1);
    
        int random = distShip(gen);
        shipPositions.push_back(shipFunc[random]());
    
        if (game.getStageDiff() > 3) {
            uniform_int_distribution<int> distCount(1, 4);  // Number of extra ships to add
            int extraShips = distCount(gen);
    
            for (int i = 0; i < extraShips; ++i) {
                int shipRand = distShip(gen);
                shipPositions.push_back(shipFunc[shipRand]());
            }
        }
    }

    //Calculate  number of ship parts
    game.calculateShipParts(test,shipPositions);
    
    //Values to prevent duplicate prints
    int secondPrint = 0;
    int firstprint = 0;
    
    
    if (firstprint == 0){
        displayBoard(test,rows,cols,game.getStageDiff()); //Display board
        firstprint++;
    } 
	
    //Hide Ships
    
    bool running = true;

	while (running) {
        
        //Win screen
        if (game.getShipParts() <= game.getHitCount() ){
            cout <<endl;
            cout <<endl;
            cout << setw(80) << "     _   _   _    _____    ____     _   _ " <<endl;
            cout << setw(80) << "    | | | | | |  |_   _|  |    |   | |  | |" <<endl;
            cout << setw(80) << "    | | | | | |    | |    |  _  |  | |  | |" <<endl;
            cout << setw(80) << "    | |_| |_| |   _| |_   |  | | | | |  |_|" <<endl;
            cout << setw(80) << "    |_________|  |_____|  |__|  |____|   + " <<endl;
            cout <<endl;
            cout <<endl;
            
            //Set new high score and incrase difficulty
            game.setHighScore(game.getScore());
            game.incrementStageDif();
            
            cout << "Nice Job, you've beaten this fleet! Whats next commandar?\n";
            cout << "1. Next Level: (board size = " << to_string(game.getStageDiff() + 10) << "x" << to_string(game.getStageDiff() + 10) << ")" << endl;
            cout << "2. Back to main menu: (Your score ends here)\n";
            cout << "Choose an option: ";   
            
            //get option
            int choice;
            cin >> choice;
            cin.ignore();
            
            switch (choice){
            case 1: //Next level
                clearScreen();
                startGame(game,items);
                return;
            
            case 2://Reset game
                game.resetMissile();
                game.calculateCash(game.getScore());
                running = false;
                return; // exit loop    
            
            default:
                break;
            }
        }

        //Game over screen
        if (game.getMissile() == 0 ) {
            //Reveal ships and calculate cash
            revealShips(shipPositions,test);
            displayBoard(test,rows,cols,game.getStageDiff());
            game.calculateCash(game.getScore());
            
            game.addMissile(15);
            cout <<endl;
            cout <<endl;
            cout << setw(80) << " ______    _______    _________    _______      _______   __      __   _______    _______     _ " <<endl;
            cout << setw(80) << "| _____|  |  ___  |  |  _   _  |  |  _____|    |  ___  |  | |    | |  |  _____|  |       |   | |" <<endl;
            cout << setw(80) << "| |   _   | |___| |  | | |_| | |  | |_____     | |   | |   | |  | |   | |_____   |  ___ |    | |" <<endl;
            cout << setw(80) << "| |__| |  | |   | |  | |     | |  |  _____|    | |___| |    | || |    |  _____|  | |   | |   |_|" <<endl;
            cout << setw(80) << "|______|  |_|   |_|  |_|     |_|  |_______|    |_______|     |__|     |_______|  |_|    |_|   + " <<endl;
            cout <<endl;
            cout <<endl;

            //set high score
            game.setHighScore(game.getScore());
            cout << "Hit Count: " << game.getHitCount() << endl;
            cout << "\033[38;5;44mCurrent Score: " << to_string(game.getScore()) << "\033[0m\n";
            cout << "\033[38;2;60;179;113mCash: $" << to_string(game.getCash()) << "\033[0m\n";
            cout << endl;
            cout << "\nGo back to the main menu to spend your cash in the Warehouse!\nPress Enter to return.";
            cin.ignore();
            break;
        } 

        if (items.torpedoState.isOn){
            items.updateTorpedo(shipPositions,test,game);
        }

        if (secondPrint >=1){
            displayBoard(test,rows,cols,game.getStageDiff()); //Display board
        }
        secondPrint++;

        //Print stats
        cout << "Current Stage: " << 1 + game.getStageDiff() << " | Board size: " << boardSize << "x" << boardSize << endl;
        cout << "Personal Best: " << game.getHighscore() << endl;
        cout << "Ship parts: " << game.getShipParts() << endl;
        cout << "Hit Count: " << game.getHitCount() << endl;
        cout << "Items: (Helicopter Scout(s): " << items.getHeliScout() << ") | (Ballistic Missile(s): " << items.getBallisticMissile() << ") | (Sonar(s): " << items.getSonar() << ") | (Torpedo(s): " << items.getTorpedo() << ")\n";
        cout << "\033[38;5;44mCurrent Score: " << to_string(game.getScore()) << "\033[0m\n"; 
        cout << "\033[38;2;60;179;113mCash: $" << to_string(game.getCash()) << "\033[0m\n";
        cout << "You have\033[38;2;255;105;180m " << to_string(game.getMissile()) << " Missle(s)\033[0m." << endl;  
        cout << endl <<endl;

        
        //Print prompt
        string userInput;
        cout << "Commandar, whats your next move!?" << endl;
		cout << "Pick a postion to fire a missle on: ('B6')\n";
        cout << "Select an item to use: (I)\n";
        cout << "Surrender: (-)\n";
        cout << "Choice: ";

        game.setHighScore(game.getScore());
        if (cin.peek() == '\n') cin.ignore();  // flush leftover newline
		getline(cin,userInput);

		
        

   	 	// Remove spaces if there is any
		userInput.erase(remove(userInput.begin(), userInput.end(), ' '), userInput.end());
        
        //Surrender
        if (userInput == "-"){
            cout << "You've Surrendered... Press Enter to continue";
            cin.ignore();
            running = false;
            break; // exit loop

        }

        if(userInput == "+"){
           revealShips(shipPositions,test);
        }
        
        //Item Menu
        if (userInput == "I" || userInput == "i"){
            bool flag = true;
            
            while (flag){    
                cout << endl;
                cout << "Which item would you like to use?\n";
                cout << "1. Helicopter Scout (" << items.getHeliScout() << ")\n";
                cout << "2. Ballistic Missile (" << items.getBallisticMissile() << ")\n";
                cout << "3. Sonar (" << items.getSonar() << ")\n";
                cout << "4. Torpedo (" << items.getTorpedo() << ")\n";
                cout << "5. Exit item menu\n";
                cout << "Choice: ";
                
                
                string inputStr;
                getline(cin, inputStr);

                if (inputStr.empty()) {
                    continue; // re-show menu if empty
                }

                int choice;
                try {
                    choice = stoi(inputStr);
                } catch (...) {
                    cout << "Invalid input! Please enter a number between 1 and 5.\nPress Enter to try again.\n";
                    cin.ignore();
                    continue;
                 }

                cout << endl;
                switch (choice){
                case 1:
                    items.useHelicopterScout(shipPositions,test);
                    flag = false; 
                    cin.ignore();
                    break;
                case 2:
                    items.useBallisticMissile(shipPositions,test,game);
                    flag = false; 
                    cin.ignore();
                    break;   
                
                case 3:
                    items.useSonar(shipPositions,test);
                    flag = false; 
                    cin.ignore();
                    break;
                case 4:
                    items.activateTorpedo(test,game);
                    flag = false;
                    cin.ignore();
                    break;
                case 5:
                    flag = false;
                    break;
                default:
                    cout << "Invalid choice. Enter 1 to 5.\n";
                    cin.ignore();
                    break;
                }
            }
            clearScreen();
            continue;
        }

        
        char userColumn = toupper(userInput[0]); //If user input is lowercase number
        int userRow;
        

        try {
            userRow = stoi(userInput.substr(1)); //Converts the number part of the string to an int

        }catch (const invalid_argument& e) {
            cout << "Invalid input, try 'B5' or 'A10' Letter first. Enter to continue" << endl;
            cin.ignore();
            clearScreen();
            continue;
        }

        
        clearScreen();
        hitormiss.checkHit(test, shipPositions, userRow, userColumn, game, combo, userInputs);
		
		

	}
}

void mainMenu() {
    
    Items items;
    Game game;
    bool running = true;


    while (running) {
        
        int stageIncrement = 0;
        string cash = to_string(game.getCash());
        string score = to_string(game.getScore());
        string missles = to_string(game.getMissile());
        string highScore = to_string(game.getHighscore());
        game.setHighScore(game.getScore());

        clearScreen();
        cout << "=========== MAIN MENU ===========" << left << setw(15) << "=" << "(\033[38;5;44mCurrent Highscore: " << highScore << "\033[0m)\n";
        cout << "1. (Start Game" << left << setw(34) << ")" << "(\033[38;2;255;105;180mMissles: " << missles << "\033[0m)\n";
        cout << "2. (Instructions)\n";
        cout << "3. (Warehouse" << left << setw(35) << ")" << "(\033[38;2;60;179;113mBank: $" << cash << "\033[0m)\n";
        cout << "4. (Exit)\n";
        cout << "Choose an option: ";



        string inputStr;
        getline(cin, inputStr);

        if (inputStr.empty()) {
            continue; // re-show menu if empty
        }

        int choice;
        try {
            choice = stoi(inputStr);
        } catch (...) {
            cout << "Invalid input! Please enter a number between 1 and 5.\nPress Enter to try again.\n";
            cin.ignore();
            continue;
        }

        switch (choice) {
            case 1:
                clearScreen();
                startGame(game,items);
                break;
            case 2:
                clearScreen();
                cout << "\nInstructions:\n- You have missles to shoot ships.\n- Enter coordinates like A5.\n- Sink all ships to win.\n- As you sink ships, you will gain cash to spend in the warehouse for new equipment.\n\nPress Enter to return.";
                cin.ignore();
                break;
            case 3:
                clearScreen();
                shopMenu(game,items);
                break;
            case 4:
                running = false;
                break;
            case 5:
                game.addCash(20000);
                break;
            case 6:
                game.addMissile(100);
                break;
            default:
                cout << "Invalid option.\n";
        }
    }
}


void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

void soldierAnimation(){


    cout << "       .---." << endl;
    cout << "  ___ /_____\\" << endl;
    cout << " /\\.-`( '.' )             COMMANDER! You're finally here!" << endl;
    cout << "/ /    \\_-_/_" << endl;
    cout << "\\ `-.-``'V'//-." << endl;
    cout << " `.__,   |// , \\" << endl;
    cout << "     |Ll //Ll|\\ \\" << endl;
    cout << "     |__//   | \\_\\" << endl;
    cout << "    /---|[]==| / /" << endl;
    cout << "    \\__/ |   \\/\\/" << endl;
    cout << "     |__//   | \\_\\" << endl;
    cout << "    /_   | Ll_\\|" << endl;
    cout << "     |`^```^`| " << endl;
    cout << "     |   |   | " << endl;
    cout << "     |   |   | " << endl;
    cout << "     |   |   | " << endl;
    cout << "     |   |   | " << endl;
    cout << "     L___l___J " << endl;
    cout << "      |_ | _| " << endl;
    cout << "     (___|___) " << endl;
    cout << "\n\n Press Enter to continue.";
    cin.ignore();
    clearScreen();
    cout << "       .---." << endl;
    cout << "  ___ /_____\\" << endl;
    cout << " /\\.-`( '.' )             There is an fleet of ships heading straight towards!" << endl;
    cout << "/ /    \\_-_/_             The enemy fleet is massive, more than we anticipated." << endl;
    cout << "\\ `-.-``'V'//-." << endl;
    cout << " `.__,   |// , \\" << endl;
    cout << "     |Ll //Ll|\\ \\" << endl;
    cout << "     |__//   | \\_\\" << endl;
    cout << "    /---|[]==| / /" << endl;
    cout << "    \\__/ |   \\/\\/" << endl;
    cout << "     |__//   | \\_\\" << endl;
    cout << "    /_   | Ll_\\|" << endl;
    cout << "     |`^```^`|" << endl;
    cout << "     |   |   |" << endl;
    cout << "     |   |   |" << endl;
    cout << "     |   |   |" << endl;
    cout << "     |   |   |" << endl;
    cout << "     L___l___J" << endl;
    cout << "      |_ | _|" << endl;
    cout << "     (___|___)" << endl;
    cout << "\n\n Press Enter to continue.";
    cin.ignore();
    clearScreen();

    cout << "       .---." << endl;
    cout << "      /_____\\" << endl;
    cout << "      ( '.' )           It's do or die now Commander, we've loaded a ship with 15 missles awaiting your commands" << endl;
    cout << "       \\_-_/_           Godspeed." << endl;
    cout << "    .- `'V'//-." << endl;
    cout << "   / ,   |// , \\" << endl;
    cout << "  / /|Ll //Ll|\\ \\" << endl;
    cout << " / / |__//   | \\_\\" << endl;
    cout << " \\ \\/---|[]==| / /" << endl;
    cout << "  \\/\\__/ |   \\/\\/" << endl;
    cout << "   |/_   | Ll_\\|" << endl;
    cout << "     |`^```^`|" << endl;
    cout << "     |   |   |" << endl;
    cout << "     |   |   |" << endl;
    cout << "     |   |   |" << endl;
    cout << "     |   |   |" << endl;
    cout << "     L___l___J" << endl;
    cout << "      |_ | _|" << endl;
    cout << "     (___|___)" << endl;
    cout << "\n\n Press Enter to continue.";
    cin.ignore();
    clearScreen();
    

}

//Function to display board
void displayBoard(vector<vector<string>> &board , int rows, int cols,int stageIcrement){
    
    // Print column headers letters
    cout << right << setw(95-stageIcrement);
    for (char ch = 'A'; ch < 'A' + cols; ++ch) {
        cout << ch << "  ";
    }
    
    cout << endl;

    // Print each row with row number starting from 1
    for (int r = 0; r < rows; r++) {
        cout << setw(90-stageIcrement);
        if (r + 1 < 10 )
            cout << " " << r + 1 << "  ";  // Align single-digit row numbers
        else
            
            cout  << " " << r + 1 << " ";         // No extra space needed for two-digit

        for (int c = 0; c < cols ; c++) {
            
            cout << board[r][c];
        }
        cout << endl;
    }
}

//Reveal board after game over
void revealShips(vector<vector<pair<int,int>>> &shipPositions, vector<vector<string>> &board) {

    for (const auto &ship : shipPositions) {
        for (const auto &pos : ship){
            
            int row = pos.first;
            int col = pos.second;

            if (board[row][col] != "[X]") { board[row][col] = "[*]";}
          
             
        }
    }
    

}


//cd "D:\C++ CLASSES\CSIS 297 CLASS\Battleship step 3\bin"
//g++ -o main.exe ../main.cpp ../Ship.cpp ../Board.cpp

//Game before game starts.
//15 rockets
//Game keeps going until 0
   // Make new board if all ships are found and game is no over
   //Display how many ship pieces are left
   //After a game, gain gold to spend in shop



   
//Every turn, a user can decide to use an item so what do we do?
    //Menu
    //COMMANDAR WHAT WOULD YOU LIKE TO DO?
    //1. Fire a rocket
        //Run hit or miss
    //2. Use item
        //What item would like to use
        //Helicopter Scout
            //Use sonar on board
        //
        //Super missle
            //Use new hit or miss for super missle
        //Sonar
        //Torpedo
            //This one is going to have to take board after every turn

    //3. Exit round (Score ends here)



//Add a super missle, Makes a 3x3 mark
    //Get position of where user shot,
    //Check position left right up down, then go from up right, make sure certain positions are valid to check
    //If there is something there, mark it with X, none with O


//Add sonar by using ship positions vector, reveals 3 (NAME IT HELICOPTER SCOUT)
    //
    // afte pruchasing sonar, set a boolean to true, now prints in item bar
    // make a function that takes the ship positions, the boolean,
        //Ship postion iteraters through all of the positions and randomly picks out a position to mark with = [*]
//Super sonar, same thing as sonar but reveals 8 random spots.

//Add torpedo
    //Takes board and ship positions
        // Starts from bottom of screen and continues forward after every turn
            //So we're gonna need to update board twice before printing, user input + torpedo input.
