#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define EMPTY 0
#define PLAYER1 1
#define PLAYER2 2

typedef struct {
    int size;  // �Ѥl�j�p        0 - �L     || 1 - �p     ||  2 - ��      || 3 - �j
    int owner; // �Ѥl�ݩ󪱮a��  0 - �L     || 1 - ���a1  ||  2 - ���a2
} Cell;

Cell board[3][3]; // 3 x 3 �ѽL
int pieces[2][3] = { {2, 2, 2}, {2, 2, 2} }; // ���a�U�۪��ѩ�Ѥl�� : �p�B���B�j

//�إߴѽL
//void initializeBoard()

//�C�L�ѽL
//void printBoard()

//�ˬd�O�_�����a���
bool checkWin(int player) {
    for (int i = 0; i < 3; i++) {
        // �ˬd��ΦC
        if ((board[i][0].owner == player && board[i][1].owner == player && board[i][2].owner == player) ||
            (board[0][i].owner == player && board[1][i].owner == player && board[2][i].owner == player)) {
            return true;
        }
    }
    // �ˬd�﨤�u
    if ((board[0][0].owner == player && board[1][1].owner == player && board[2][2].owner == player) ||
        (board[0][2].owner == player && board[1][1].owner == player && board[2][0].owner == player)) {
        return true;
    }
    return false;
 }

//�ˬd��m�Ѥl�ɡA���L�X�G�޿�
bool placePiece(int player, int size, int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        printf("��m�W�X�ѽL�d��I\n");
        return false;
    }
    if (pieces[player - 1][size - 1] <= 0) {
        printf("�S���Ѿl���Ӥj�p�Ѥl�I\n");
        return false;
    }
    if (board[row][col].size >= size) {
        printf("��e��m�w���۵��Χ�j���Ѥl�I\n");
        return false;
    }
    // ��m�Ѥl
    board[row][col].size = size;
    board[row][col].owner = player;
    pieces[player - 1][size - 1]--;
    return true;
}

int main() {
    
   

}