#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PLAYER1 1
#define PLAYER2 2

//�إߴѽL
//void initializeBoard()

//�C�L�ѽL
//void printBoard()

//�ˬd�O�_�����a���
//bool checkWin()

//�ˬd��m�Ѥl�ɡA���L�X�G�޿�
//bool placePiece()

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