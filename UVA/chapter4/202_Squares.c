#include <stdio.h>
#include <memory.h>

typedef struct{
    int hl;
    int hr;
    int vu;
    int vd;
}Point;


int check(Point* cur, int n){
    //hr & vd
    ///
    for (int i = 0; i < n; i++){
        if ((cur + i)->hr != 1) return 0;
        if ((cur + i * 10)->vd != 1) return 0;
    }

    //hl & vu
    cur = cur + n * 10 + n;
    for (int i = 0; i < n; i++){
        if ((cur - i)->hl != 1) return 0;
        if ((cur - i * 10)->vu != 1) return 0;
    }

    return 1;
}

// n = size of square; d = number of dots
int find(int n, int d, Point square[10][10]){
    int num = 0;
    for (int i = 0; i < d - n; i++){
        for (int j = 0; j < d - n; j++){
            num += check(&square[i][j], n);            
        }
    }
    return num;
}

int main(){
    int n; // number of dots in a line
    int problem = 0;
    Point square[10][10];

    while(scanf("%d", &n) != EOF){
        if (problem >= 1) printf("\n**********************************\n\n");
        int m; // number of lines
        scanf("%d", &m);
        
        memset(square, 0, sizeof(square));      
        problem++;  

        while (m--){
            char c[5];
            int i, j;
            scanf("%s%d%d", c, &i, &j);

            if (c[0] == 'H'){
                square[i - 1][j - 1].hr = 1;
                square[i - 1][j].hl = 1;
            }else{
                square[j - 1][i - 1].vd = 1;
                square[j][i - 1].vu = 1;
            }
        }

        printf("Problem #%d\n\n", problem);

        int exist = 0;
        for (int i = 1; i < n; i++){
            int num_s = find(i, n, square);
            if (num_s) {
                printf("%d square (s) of size %d\n", num_s, i);
                exist = 1;
            };
        }
        if (exist == 0) printf("No completed squares can be found.\n");
    }
}