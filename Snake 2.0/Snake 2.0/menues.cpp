#include <iostream>
#include "menues.h"
#include <fstream>
#include "table.h"


void ScoreMenu(){

    std::string top = "Best.txt";
    std::ifstream ist{ top };

    if (!ist) {
        std::cout << "Error to open";
        return;
    }

    int x;
    std::string y;
    int l = 5;
    int m = 5;


    while (ist >> x >> y) {
        std::cout << x << ',' << y << '\n';
    }
}

void DrawEnd() {
    if (Score >= 10) {
        std::cout << "Score:" << Score << '\n';
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                if (i == 0 || i == 19) {
                    Map[i][j] = UDOWN;
                }
                else if (j == 0 || j == 19) {
                    Map[i][j] = WALL;
                }
                else {
                    Map[i][j] = ESPACE;
                }
            }
        }

        // YOU WIN pe randul 8
        Map[8][6] = 'Y';
        Map[8][7] = 'O';
        Map[8][8] = 'U';
        Map[8][9] = ' ';
        Map[8][10] = 'W';
        Map[8][11] = 'I';
        Map[8][12] = 'N';

        // CONGRATULATIONS pe randul 10
        Map[10][4] = 'C';
        Map[10][5] = 'O';
        Map[10][6] = 'N';
        Map[10][7] = 'G';
        Map[10][8] = 'R';
        Map[10][9] = 'A';
        Map[10][10] = 'T';
        Map[10][11] = 'U';
        Map[10][12] = 'L';
        Map[10][13] = 'A';
        Map[10][14] = 'T';
        Map[10][15] = 'I';
        Map[10][16] = 'O';
        Map[10][17] = 'N';
        Map[10][18] = 'S';

        // 1 - RETRY si 2 - EXIT pe acelasi rand (randul 13)
        Map[13][2] = '1';
        Map[13][3] = '-';
        Map[13][4] = 'R';
        Map[13][5] = 'E';
        Map[13][6] = 'T';
        Map[13][7] = 'R';
        Map[13][8] = 'Y';
        Map[13][9] = ' ';
        Map[13][10] = ' ';
        Map[13][11] = ' ';
        Map[13][12] = ' ';
        Map[13][13] = '2';
        Map[13][14] = '-';
        Map[13][15] = 'E';
        Map[13][16] = 'X';
        Map[13][17] = 'I';
        Map[13][18] = 'T';

        // Afisare matrice
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                std::cout << Map[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }
    else {
        // Resetare matrice cu pereti
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                if (i == 0 || i == 19) {
                    Map[i][j] = UDOWN;
                }
                else if (j == 0 || j == 19) {
                    Map[i][j] = WALL;
                }
                else {
                    Map[i][j] = ESPACE;
                }
            }
        }

        // GAME OVER pe randurile 8-10
        Map[8][5] = 'G';
        Map[8][6] = 'A';
        Map[8][7] = 'M';
        Map[8][8] = 'E';
        Map[8][9] = ' ';
        Map[8][10] = 'O';
        Map[8][11] = 'V';
        Map[8][12] = 'E';
        Map[8][13] = 'R';

        // 1 - RETRY si 2 - EXIT pe aceeasi linie (randul 12)
        Map[11][2] = '1';
        Map[11][3] = '-';
        Map[11][4] = 'R';
        Map[11][5] = 'E';
        Map[11][6] = 'T';
        Map[11][7] = 'R';
        Map[11][8] = 'Y';
        Map[11][9] = ' ';
        Map[11][10] = ' ';
        Map[11][11] = ' ';
        Map[11][12] = ' ';
        Map[11][13] = '2';
        Map[11][14] = '-';
        Map[11][15] = 'E';
        Map[11][16] = 'X';
        Map[11][17] = 'I';
        Map[11][18] = 'T';

        // Afisare matrice
        std::cout << "Score:" << Score << '\n';

        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                std::cout << Map[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }

}