# Battleship-Roguelite-Game

A terminal-based endless Battleship game built in C++.  
Start with limited resources and fight through as many stages as you can — earning money, buying upgrades, and pushing for the highest score in a single run.

---------------------

#Game loop
-Start with 15 missiles and face your first fleet, each fleet is randomly generated with 5 ships
-Destroy as many ships as you can earning money to spend in the warehouse.
-Once you run of it missiles, your run is over.
-After each run, you can go spend your cash in the warehouse for items, these items will allow you to make it further in the game and get a higher score.
-After each stage, the board gets bigger and there is a chance to spawn more ships causing bigger fleets.
-Try to get the highest score you can!


#Screenshots
![Gameplay Screenshot](13x13Board.png)
![Gameplay Screenshot](Hit.png)
![Gameplay Screenshot](Miss.png)
![Gameplay Screenshot](Startscene.png)
![Gameplay Screenshot](TorpedoandSonar.png)
![Gameplay Screenshot](Warehouse.png)

##How to compile
-Open a terminal inside the project folder, outside of src.
-Paste this into your terminal: g++ src/*.cpp -o main
-After the main.exe is built, type .\main to run!