//Title: Battleship Program
//Author: Joe Glogowski
//Date: November 30, 2023
//Filename: 2dBattleship
//Purpose: Battleship Program

#include <iostream>
#include <iomanip>

void printGrid(int shipGrid[4][4]);
int inputShips(int *gridPtr);
void checkHit(int shipGrid[4][4]);

int main() {

    int shipGrid[4][4] ={{0, 0, 0, 0},{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int* gridPtr = &shipGrid[0][0];
    int ships = 0;

    printGrid(shipGrid);
    inputShips(gridPtr);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (shipGrid[i][j] == 1) {
                ships++;
            }
        }
    }

    while(ships > 0) {
        printGrid(shipGrid);

        checkHit(shipGrid);

        ships = 0;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (shipGrid[i][j] == 1) {
                    ships++;
                }
            }
        }
        
        if(ships == 0){
            std::cout << "All ships sank!" << std::endl;
        }


    }
}

void printGrid(int shipGrid[4][4]) {
    int info = 0;

    std::cout << "  __0___1___2___3___" << std::endl;


    for(int i = 0; i < 4; i++){
        std::cout << info << " |";
        info++;
        for(int j = 0; j < 4; j++){
            std::cout << "" << std::setw(3) << shipGrid [i][j] << "|";
        }
        std::cout << std::endl;
    }
    std::cout << "  __________________" << std::endl;
}

int inputShips(int *gridPtr){

    int checkInput;

    do{
        int inx, iny;

        std::cout << "Enter the coords of where you want to enter ship" << std::endl<< "Enter x:";
        std::cin >> inx;
        std::cout << "Enter y: ";
        std::cin >> iny;

        gridPtr[iny * 4 + inx] = 1;
        std::cout << "Would you like place another ship " << std::endl << "yes = 1" << std::endl << "no = 0" << std::endl;
        std::cin >> checkInput;

    }while(checkInput == 1);
    return 0;
}

void checkHit(int shipGrid[4][4]){
    int x, y;
    std::cout << "Enter the coords of the space you want to shoot" << std::endl << "Enter x:";
    std::cin >> x;
    std::cout << "Enter y:";
    std::cin >> y;

    if (shipGrid[y][x] == 1){
        shipGrid[y][x] = 0;
        std::cout << "HIT!!!" << std::endl;
    } else {
        std::cout << shipGrid[x][y];
        std::cout << "miss :(" << std::endl;
    }
}