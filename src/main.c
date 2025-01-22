#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingo.h"

#define ROWS 5
#define COLS 5

int main() {
    srand(time(0));

    int bingoCard[ROWS][COLS] = {{0}};

    int start[COLS] = {1, 16, 31, 46, 61};
    int end[COLS] = {15, 30, 45, 60, 75};

    for (int col = 0; col < COLS; col++) {
        int numbers[ROWS];

        // Cria espaço vazio no meio (indiozinho)
        if (col == 2) {
            generateColumn(numbers, ROWS -1, start[col], end[col]);
            numbers[2] = 0;
        } else {
            generateColumn(numbers, ROWS, start[col], end[col]);
        }

        sortColumn(numbers, (col == 2) ? ROWS - 1 : ROWS);

        for (int row = 0; row < ROWS; row++) {
            bingoCard[row][col] = numbers[row];
        }

    }

    printBingoCard(bingoCard);

    return 0;
}