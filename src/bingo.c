#include <stdio.h>
#include <stdlib.h>
#include <bingo.h>

int isNumberUsed(int column[], int size, int number) {
    for (int i = 0; i < size; i++) {
        if (column[i] == number) {
            return 1;
        }
    }

    return 0;
}

void generateColumn(int column[], int size, int start, int end) {
    for (int i = 0; i < size; i++) {
        int number;
        do {
            number = rand() % (end - start + 1) + start;            
        } while (isNumberUsed(column, i, number));

        column[i] = number;
    }
}

void sortColumn(int column[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (column[j] > column[j + 1]) {
                int temp = column[j];
                column[j] = column[j + 1];
                column[j + 1] = temp;
            }
        }
    }
}

void printBingoCard(int card[ROWS][COLS]) {
    printf("  C   I   N   G   O\n");
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (col == 2 && row == 2) {
                printf(" *  ");
            } else {
                printf("%3d ", card[row][col]);
            }
        }
        printf("\n");
    }
}