#include <stdio.h>
#include <memory.h>

int dxs[3] = {0, -1, 1};
int dys[3] = {0, -1, 1};

void print_board(int board[10][10]){
    for (int i = 1; i <= 8; i++){
        for (int j = 1; j <= 8; j++)
            printf("%c", board[i][j]);
        printf("\n");
    }
}

//make sure 1 is the smaller one
//for diagnal, make sure row1 < row2
void change_color(int row1, int col1, int row2, int col2, int board[10][10], char color){
    //change color horizontally    
    if (row1 == row2){
        for (int i = col1 + 1; i < col2; i++){
            board[row1][i] = color;
        }
        return;
    }

    //change color vertically
    if (col1 == col2){
        for (int i = row1 + 1; i < row2; i++)
            board[i][col1] = color;
        return;
    }

    //change color diagonally
    if (col1 < col2)
        for (int i = 1; row1 + i < row2; i++)
            board[row1 + i][col1 + i] = color;
    else
        for (int i = 1; row1 + i < row2; i++)
            board[row1 + i][col1 - i] = color;
}


int find_bracket(int row, int col, int board[10][10], int is_change, char player){
    int has_bracket = 0;
    int see_enemy = 0;    

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(i == 0 && j == 0) continue;
            int dx = dxs[i], dy = dys[j];
            int cx = row, cy = col;
            see_enemy = 0;

            while (cx + dx <= 8 && cx + dx >= 1 && cy + dy <= 8 && cy + dy >= 1){
                cx += dx;
                cy += dy;
                if (board[cx][cy] == '-') break;
                if (board[cx][cy] != player) see_enemy = 1;
                else{
                    if (see_enemy){
                        has_bracket = 1;
                        if (is_change){
                            while (cx != row || cy != col){
                                cx -= dx;
                                cy -= dy;
                                board[cx][cy] = player;
                            }       
                        }                        
                    }
                    break;
                }
            }
        }
    }

    if (is_change)
        board[row][col] = player;
    
    return has_bracket;
}


int list_legals(int board[10][10], char player, int print){
    int has_legal = 0;
    //print_board(board);
    for (int i = 1; i <= 8; i++){
        for (int j = 1; j <= 8; j++){
            if (board[i][j] == '-'){
                if (find_bracket(i, j, board, 0, player)){
                    if (print) {
                        if (has_legal) printf(" ");
                        printf("(%d,%d)", i, j);
                    }
                    has_legal++;
                }
            }
        }
    }

    if (print && !has_legal)
        printf("No legal move.");
    if (print)
        printf("\n");

    return has_legal;
}

void count_disks(int board[10][10]){
    int blacks = 0, whites = 0;
    for (int i = 1; i <= 8; i++){
        for (int j = 1; j <= 8; j++){
            if (board[i][j] == 'W') whites++;
            if (board[i][j] == 'B') blacks++;
        }
    }
    printf("Black - %2d White - %2d\n", blacks, whites);
}


int main(){

    int board[10][10];
    int boards;

    scanf("%d", &boards);

    while (boards--){
        char line[10];
        memset(board, 0, sizeof(board));
        for (int i = 1; i <= 8; i++){
            scanf("%s", line);
            for (int j = 1; j <= 8; j++)
                board[i][j] = line[j - 1];
        }

        char player;
        scanf("%s", line);
        player = line[0];
        
        while(scanf("%s", line) && line[0] != 'Q'){
            int has_legal = 0;
            if (line[0] == 'L')
                list_legals(board, player, 1);
            if (line[0] == 'M'){
                has_legal = find_bracket(line[1] - '0', line[2] - '0', board, 0, player);
                if (!has_legal) player = player == 'B' ? 'W' : 'B';
                find_bracket(line[1] - '0', line[2] - '0', board, 1, player);
                count_disks(board);
                player = player == 'B' ? 'W' : 'B'; 
            }            
        }

        print_board(board);
        if (boards)
            printf("\n");
    }

    return 0;
}