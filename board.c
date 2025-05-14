#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(){ 
    return rand() % 6 + 1; 
}

void printboard(int p1, int p2){
    for (int u=9; u>-1; u--){
        for (int o=1; o<11; o++){
            int pos = u*10+o;
            if (pos == p1) {
                printf("P1 ");
            } else if (pos == p2) {
                printf("P2 ");
            } else{
                if (u<1){
                    printf("%d  ",pos);
                } else {
                    printf("%d ", pos);
                }
            }
        }
        printf("\n");
    }

}

int main(void){
    signed int  *board = malloc(sizeof(int)*100);
    for (int i = 0; i<100; i++){
        *(board + i) = 0;
    }
    board[0] = 37;
    board[3] = 10;
    board[7] = 22;
    board[20] = 21;
    board[26] = 50;
    board[31] = -22;
    board[35] = -30;
    board[47] = -12;
    board[49] = 17;
    board[61] = -44;
    board[70] = 21;
    board[79] = 19;
    board[94] = -39;
    board[96] = -19;

    int player1 = 0;
    int player2 = 0;
    srand(time(0));
    while (player1 < 99 && player2 < 99){
        int player1rand = random();
        int player2rand = random();
        printf("Player1 Rolled %d\n", player1rand);
        player1 += player1rand;
        player1 += *(board + player1rand);
        printf("Player2 Rolled %d\n", player2rand);
        player2 += player2rand;
        player2 += *(board + player2rand);
        printboard(player1, player2);
    }
    if (player1 > 99){
        printf("Player1 Wins");
    } 
    else {
        printf("Player2 Wins");
    }
    free(board);
    return 0;
}