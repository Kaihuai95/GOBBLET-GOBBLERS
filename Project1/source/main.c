#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EMPTY 0
#define PLAYER1 1
#define PLAYER2 2

typedef struct {
    int size;
    int owner;
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
        //檢查行或列
        if ((board[i][0].owner == player && board[i][1].owner == player && board[i][2].owner == player) ||
            (board[0][i].owner == player && board[1][i].owner == player && board[2][i].owner == player)) {
            return true;
        }
    }
    //檢查對角線
    if ((board[0][0].owner == player && board[1][1].owner == player && board[2][2].owner == player) ||
        (board[0][2].owner == player && board[1][1].owner == player && board[2][0].owner == player)) {
        return true;
    }
    return false;
}

//旗子放置邏輯
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
    //放置棋子
    board[row][col].size = size;
    board[row][col].owner = player;
    pieces[player - 1][size - 1]--;
    return true;
}

int main() {
    int currentPlayer = PLAYER1;
    int row, col, size;
    //initializeBoard();

    printf("歡迎來到Gobblet Gobblers! 遊戲介紹如下:\n");
    printf("這是一個進階版3x3圈圈叉叉的遊戲，遊戲目標依舊是要完成連線\n");
    printf("然而不同於普通圈圈叉叉的是，每個玩家手上有大、中、小三種棋子，每種各兩個\n");
    printf("大棋子可以蓋過對手的中棋子，中棋子可以蓋過對手的小棋子\n");
    printf("也因為這個規則，讓簡單的圈圈叉叉增加不少變數，所以，讓我們開始吧!\n");
    printf("玩家1 (X)，玩家2 (O)。\n");

    while (true) {
        //printBoard();
        printf("玩家 %d 的回合！\n", currentPlayer);
        printf("請先輸入棋子大小 (1-小, 2-中, 3-大): ");
        scanf("%d", &size);
        printf("請輸入要放在第幾行(水平) (0-2): ");
        scanf("%d", &row);
        printf("請輸入要放在第幾列(垂直) (0-2): ");
        scanf("%d", &col);
        /*
        if (placePiece(currentPlayer, size, row, col)) {
            if (checkWin(currentPlayer)) {
                printBoard();
                printf("玩家 %d 贏了！\n", currentPlayer);
                break;
            }
            currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1;  //回合結束後，攻守交換
        }
        else {
            printf("這是無效操作，請重試！\n");
        }
        */
    }

    return 0;

}