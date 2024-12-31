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

Cell board[3][3]; // 3 x 3 �ѽL
int pieces[2][3] = { {2, 2, 2}, {2, 2, 2} }; // ���a�U�۪��ѩ�Ѥl�� : �p�B���B�j

//�إߴѽL
//void initializeBoard()

//�C�L�ѽL
//void printBoard()

//�ˬd�O�_�����a���
bool checkWin(int player) {
    for (int i = 0; i < 3; i++) {
        //�ˬd��ΦC
        if ((board[i][0].owner == player && board[i][1].owner == player && board[i][2].owner == player) ||
            (board[0][i].owner == player && board[1][i].owner == player && board[2][i].owner == player)) {
            return true;
        }
    }
    //�ˬd�﨤�u
    if ((board[0][0].owner == player && board[1][1].owner == player && board[2][2].owner == player) ||
        (board[0][2].owner == player && board[1][1].owner == player && board[2][0].owner == player)) {
        return true;
    }
    return false;
}

//�X�l��m�޿�
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
    //��m�Ѥl
    board[row][col].size = size;
    board[row][col].owner = player;
    pieces[player - 1][size - 1]--;
    return true;
}

int main() {
    int currentPlayer = PLAYER1;
    int row, col, size;
    //initializeBoard();

    printf("�w��Ө�Gobblet Gobblers! �C�����Цp�U:\n");
    printf("�o�O�@�Ӷi����3x3���e�e���C���A�C���ؼШ��¬O�n�����s�u\n");
    printf("�M�Ӥ��P�󴶳q���e�e���O�A�C�Ӫ��a��W���j�B���B�p�T�شѤl�A�C�ئU���\n");
    printf("�j�Ѥl�i�H�\�L��⪺���Ѥl�A���Ѥl�i�H�\�L��⪺�p�Ѥl\n");
    printf("�]�]���o�ӳW�h�A��²�檺���e�e�W�[�����ܼơA�ҥH�A���ڭ̶}�l�a!\n");
    printf("���a1 (X)�A���a2 (O)�C\n");

    while (true) {
        //printBoard();
        printf("���a %d ���^�X�I\n", currentPlayer);
        printf("�Х���J�Ѥl�j�p (1-�p, 2-��, 3-�j): ");
        scanf("%d", &size);
        printf("�п�J�n��b�ĴX��(����) (0-2): ");
        scanf("%d", &row);
        printf("�п�J�n��b�ĴX�C(����) (0-2): ");
        scanf("%d", &col);
        /*
        if (placePiece(currentPlayer, size, row, col)) {
            if (checkWin(currentPlayer)) {
                printBoard();
                printf("���a %d Ĺ�F�I\n", currentPlayer);
                break;
            }
            currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1;  //�^�X������A��u�洫
        }
        else {
            printf("�o�O�L�ľާ@�A�Э��աI\n");
        }
        */
    }

    return 0;

}