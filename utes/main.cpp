#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void printBoard() {
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("---|---|---\n");
    }
}

int checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ') return board[i][0];
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ') return board[0][i];
    }
    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' '))
        return board[1][1];
    return ' ';
}

void playerMove() {
    int x, y;
    do {
        printf("do radku #(1-3): ");
        if (scanf("%d", &x) != 1 || x < 1 || x > 3) {
            printf("haha co skusas! iba do troch ty had .\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        printf("do stplca #(1-3): ");
        if (scanf("%d", &y) != 1 || y < 1 || y > 3) {
            printf("haha co skusas! iba do trocj ty had.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        x--, y--; // Convert to 0-based indexing
        if (board[x][y] != ' ') {
            printf("iba do 3 ty bazmek.\n");
            continue;
        }
        break; // Valid input, break the loop
    } while (1);
    board[x][y] = PLAYER;
}

void computerMove() {
    int x, y;
    do {
        x = rand() % 3, y = rand() % 3;
    } while (board[x][y] != ' ');
    board[x][y] = COMPUTER;
}

int main() {
    srand(time(0));
    char winner, response;
    do {
        winner = ' ';
        resetBoard();
        while (winner == ' ') {
            printBoard();
            playerMove();
            if ((winner = checkWinner()) != ' ' || !(response = 9)) break;
            computerMove();
            if ((winner = checkWinner()) != ' ') break;
        }
        printBoard();
        printf("%s", (winner == PLAYER) ? "W!" : (winner == COMPUTER) ? "L!" : "nic z toho!");
        printf("\nisto chces hrat znova? (Y/N): ");
        scanf(" %c", &response);
    } while (toupper(response) == 'Y');
    printf("dik brona!");
    return 0;
}