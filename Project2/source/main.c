#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EMPTY 0      //����
#define PLAYER1 1
#define PLAYER2 2

typedef struct {
    int size;  // �Ѥl�j�p       0 - �L     || 1 - �p     ||  2 - ��      || 3 - �j
    int owner; // �Ѥl�ݩ󪱮a��  0 - �L     || 1 - ���a1  ||  2 - ���a2
} Cell;

Cell board[3][3]; // 3 x 3 �ѽL
int pieces[2][3] = { {2, 2, 2}, {2, 2, 2} }; // ���a�U�۪��ѩ�Ѥl�� : �p�B���B�j

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
    printf("�ثe���a %d �Ѿl�Ѥl: �p-%d ��-%d �j-%d\n",
        player, pieces[player - 1][0], pieces[player - 1][1], pieces[player - 1][2]);
    return true;
}

// ��l�ƴѽL
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j].size = EMPTY;   //��l�Ʈ�l��'X','O'���j�p
            board[i][j].owner = EMPTY;  //��l�Ʈ�l���֦���
        }
    }
}

// �C�L�ѽL
void printBoard() {
    printf("\n�ѽL���A:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j].owner == EMPTY) {   //�P�_��l�O�_���Q����
                printf("[   ] ");
            }
            else {
                printf("[%c%d] ", board[i][j].owner == PLAYER1 ? 'X' : 'O',
                    board[i][j].size);  //�P�_�O�_�����a�@  YES'X'  NO'O',�æC�X�L�̩�Ѥl���j�p
            }
        }
        printf("\n");
    }
}

int main() {
    int currentPlayer = PLAYER1;
    int row, col, size;
    initializeBoard();

    printf("�w��Ө�Gobblet Gobblers! �C�����Цp�U:\n");
    printf("�o�O�@�Ӷi����3x3���e�e���C���A�C���ؼШ��¬O�n�����s�u\n");
    printf("�M�Ӥ��P�󴶳q���e�e���O�A�C�Ӫ��a��W���j�B���B�p�T�شѤl�A�C�ئU���\n");
    printf("�j�Ѥl�i�H�\�L��⪺���Ѥl�A���Ѥl�i�H�\�L��⪺�p�Ѥl\n");
    printf("�]�]���o�ӳW�h�A��²�檺���e�e�W�[�����ܼơA�ҥH�A���ڭ̶}�l�a!\n");
    printf("���a1 (X)�A���a2 (O)�C\n");

    while (true) {
        printBoard();
        printf("���a %d ���^�X�I\n", currentPlayer);
        printf("�Х���J�Ѥl�j�p (1-�p, 2-��, 3-�j): ");
        scanf("%d", &size);
        printf("�п�J�n��b�ĴX��(����) (0-2): ");
        scanf("%d", &row);
        printf("�п�J�n��b�ĴX�C(����) (0-2): ");
        scanf("%d", &col);

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
    }

    system("pause");
    return 0;
}