#include<stdio.h>
#include<ctype.h>
#include<cstring>
#include<stdlib.h>

int main(){

#ifdef FREOPEN
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    char ch;
    int puzzleNum = 0;

    ch = getc(stdin);


    while (ch != 'Z'){
        if (puzzleNum)
            printf("\n");

        puzzleNum++;

        int numCol = 0, numRow = 0;
        int empCol = 0, empRow = 0;
        int error = 0;
        char puzzle[5][5];

        while (numRow < 5){
            numCol = 0;
            while (numCol < 5){
                puzzle[numRow][numCol] = ch;
                if (numCol == 4 && ch == '\n'){
                    empCol = numCol;
                    empRow = numRow;
                    puzzle[numRow][numCol] = ' ';
                }else{
                    if (ch == ' ')
                    {
                        empCol = numCol;
                        empRow = numRow;
                    }
                    ch = getc(stdin);
                }
                numCol++;
            }
            ch = getc(stdin);
            numRow++;
        }

        while (ch != '0'){
            switch (ch)
            {
            case 'A':
                if (empRow == 0){
                    error = 1;
                }else{
                    puzzle[empRow][empCol] = puzzle[empRow - 1][empCol];
                    puzzle[empRow - 1][empCol] = ' ';
                    empRow--;
                }
                break;
            case 'B':
                if (empRow == 4){
                    error = 1;
                }else{
                    puzzle[empRow][empCol] = puzzle[empRow + 1][empCol];
                    puzzle[empRow + 1][empCol] = ' ';
                    empRow++;
                }
                break;
            case 'L':
                if (empCol == 0){
                    error = 1;
                }else{
                    puzzle[empRow][empCol] = puzzle[empRow][empCol - 1];
                    puzzle[empRow][empCol - 1] = ' ';
                    empCol--;
                }
                break;
            case 'R':
                if (empCol == 4){
                    error = 1;
                }else{
                    puzzle[empRow][empCol] = puzzle[empRow][empCol + 1];
                    puzzle[empRow][empCol + 1] = ' ';
                    empCol++;
                }
            
            default:
                break;
            }
            ch = getc(stdin);
        }

        ch = getc(stdin);
        ch = getc(stdin);

        printf("Puzzle #%d:\n", puzzleNum);
        if (error){
            printf("This puzzle has no final configuration.\n");
        }else{
            for (int i = 0; i < 5; i++){
                for (int j = 0; j < 4; j++){
                    printf("%c ", puzzle[i][j]);
                    puzzle[i][j] = 'A';
                }
                printf("%c\n", puzzle[i][4]);
                puzzle[i][4] = 'A';
            }
        }
    }

    return 0;
}