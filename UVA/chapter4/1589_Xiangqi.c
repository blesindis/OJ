#include <stdio.h>
#include <memory.h>

int is_check(int board[15][15], int x, int y){
    //check (H) for Horse
    if (x - 2 >= 1 && board[x - 2][y - 1] == 'H' && board[x - 1][y - 1] == 0) return 1;
    if (x - 2 >= 1 && board[x - 2][y + 1] == 'H' && board[x - 1][y + 1] == 0) return 1;
    if (x - 1 >= 1 && board[x - 1][y - 2] == 'H' && board[x - 1][y - 1] == 0) return 1;
    if (x - 1 >= 1 && board[x - 1][y + 2] == 'H' && board[x - 1][y + 1] == 0) return 1;
    if (board[x + 2][y - 1] == 'H' && board[x + 1][y - 1] == 0) return 1;
    if (board[x + 2][y + 1] == 'H' && board[x + 1][y + 1] == 0) return 1;
    if (board[x + 1][y - 2] == 'H' && board[x + 1][y - 1] == 0) return 1;
    if (board[x + 1][y + 2] == 'H' && board[x + 1][y + 1] == 0) return 1;

    //check (C) for cannon and (R) for chariot
    int num = 0;
    for (int i = x; i <= 10; i++){
        if (num == 0 && (board[i][y] == 'R' || board[i][y] == 'G')) return 1;
        if (num == 1 && board[i][y] == 'C') return 1;
        if (board[i][y]) num++;
    }

    num = 0;
    for (int i = x; i >= 1; i--){
        if (num == 0 && (board[i][y] == 'R' || board[i][y] == 'G')) return 1;
        if (num == 1 && board[i][y] == 'C') return 1;
        if (board[i][y]) num++; 
    }

    num = 0;
    for (int i = y; i <= 9; i++){
        if (num == 0 && (board[x][i] == 'R' || board[x][i] == 'G')) return 1;
        if (num == 1 && board[x][i] == 'C') return 1;
        if (board[x][i]) num++;
    }

    num = 0;
    for (int i = y; i >= 1; i--){
        if (num == 0 && (board[x][i] == 'R' || board[x][i] == 'G')) return 1;
        if (num == 1 && board[x][i] == 'C') return 1;
        if (board[x][i]) num++;
    }

    return 0;
}

int flee(int board[15][15], int bg_x, int bg_y){
    int x, y;
    char ch;

    //check flying general (G)
    for(int i = bg_x; i <= 10; i++){
        if (board[i][bg_y]){
            if (board[i][bg_y] == 'G') return 1;
            else break;
        }
    }

    if (bg_x - 1 >= 1){
        x = bg_x - 1;
        y = bg_y;
        ch = board[x][y];
        board[x][y] = 0;
        if (!is_check(board, x, y)) return 1;
        board[x][y] = ch;
        
    }

    if (bg_x + 1 <= 3){
        x = bg_x + 1;
        y = bg_y;
        ch = board[x][y];
        board[x][y] = 0;
        if (!is_check(board, x, y)) return 1;
        board[x][y] = ch;
    }

    if (bg_y - 1 >= 4){
        x = bg_x;
        y = bg_y - 1;        
        ch = board[x][y];
        board[x][y] = 0;
        if (!is_check(board, x, y)) return 1;
        board[x][y] = ch;        
    }

    if (bg_y + 1 <= 6){
        x = bg_x;
        y = bg_y + 1;
        ch = board[x][y];
        board[x][y] = 0;
        if (!is_check(board, x, y)) return 1;
        board[x][y] = ch;
    }

    return 0;
    
}

int main(){

    int n;
    int board[15][15];
    int bg_x, bg_y;
    
    while (scanf("%d%d%d", &n, &bg_x, &bg_y) == 3 && n && bg_x && bg_y){
        memset(board, 0, sizeof(board));

        while(n--){
            char ch[10];
            int x, y;
            scanf("%s%d%d", ch, &x, &y);
            board[x][y] = ch[0];
        }

        if (flee(board, bg_x, bg_y)) printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}