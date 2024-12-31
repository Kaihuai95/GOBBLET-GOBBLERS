#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define EMPTY 0
#define PLAYER1 1
#define PLAYER2 2

typedef struct {
    int size;  // 棋子大小        0 - 無     || 1 - 小     ||  2 - 中      || 3 - 大
    int owner; // 棋子屬於玩家的  0 - 無     || 1 - 玩家1  ||  2 - 玩家2
} Cell;

Cell board[3][3]; // 3 x 3 棋盤
int pieces[2][3] = { {2, 2, 2}, {2, 2, 2} }; // 玩家各自的剩於棋子數 : 小、中、大

//建立棋盤
//void initializeBoard()

//列印棋盤
//void printBoard()

//檢查是否有玩家獲勝
bool checkWin(int player) {
    for (int i = 0; i < 3; i++) {
        // 檢查行或列
        if ((board[i][0].owner == player && board[i][1].owner == player && board[i][2].owner == player) ||
            (board[0][i].owner == player && board[1][i].owner == player && board[2][i].owner == player)) {
            return true;
        }
    }
    // 檢查對角線
    if ((board[0][0].owner == player && board[1][1].owner == player && board[2][2].owner == player) ||
        (board[0][2].owner == player && board[1][1].owner == player && board[2][0].owner == player)) {
        return true;
    }
    return false;
}

//檢查放置棋子時，有無合乎邏輯
bool placePiece(int player, int size, int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        printf("位置超出棋盤範圍！\n");
        return false;
    }
    if (pieces[player - 1][size - 1] <= 0) {
        printf("沒有剩餘的該大小棋子！\n");
        return false;
    }
    if (board[row][col].size >= size) {
        printf("當前位置已有相等或更大的棋子！\n");
        return false;
    }
    // 放置棋子
    board[row][col].size = size;
    board[row][col].owner = player;
    pieces[player - 1][size - 1]--;
    return true;
}

int main() {



}