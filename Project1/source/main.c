#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EMPTY 0      //為空
#define PLAYER1 1
#define PLAYER2 2

typedef struct {
    int size;  // 棋子大小        0 - 無     || 1 - 小     ||  2 - 中      || 3 - 大
    int owner; // 棋子屬於玩家的  0 - 無     || 1 - 玩家1  ||  2 - 玩家2
} Cell;

Cell board[3][3]; // 3 x 3 棋盤
int pieces[2][3] = { {2, 2, 2}, {2, 2, 2} }; // 玩家各自的剩於棋子數 : 小、中、大

// 初始化棋盤
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j].size = EMPTY;   //初始化格子放'X','O'的大小
            board[i][j].owner = EMPTY;  //初始化格子的擁有者
        }
    }
}

// 列印棋盤
void printBoard() {
    printf("\n棋盤狀態:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j].owner == EMPTY) {   //判斷格子是否有被佔領
                printf("[   ] ");
            }
            else {
                printf("[%c%d] ", board[i][j].owner == PLAYER1 ? 'X' : 'O',
                    board[i][j].size);  //判斷是否為玩家一  YES'X'  NO'O',並列出他們放棋子的大小
            }
        }
        printf("\n");
    }
}
int main() {
}