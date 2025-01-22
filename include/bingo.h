#ifndef bingo_H
#define bingo_H

#define ROWS 5
#define COLS 5

int isNumberUsed(int column[], int size, int number);
void generateColumn(int column[], int size, int start, int end);
void sortColumn(int column[], int size);
void printBingoCard(int card[ROWS][COLS]);

#endif // bingo_H