#include <stdio.h>
#include <string.h>

const int maxn = 10, maxa = 5, maxb = 5;
const long maxpos = 1000000;
char pos[maxpos][maxa + maxb + 1];
int init[maxn][3];
int n, a, b;

int addpos(int posn, char* poscur){
    for (int i = 0; i < posn; i++){
        if (strcmp(poscur, pos[i]) == 0) return 1;
    }
    strcpy(pos[posn], poscur);
    return 0;
}


int main(){
    int kase = 1;

    while(scanf("%d", &n) && n){
        int sleepn = 0;
        int repeat = 0;
        int posn = 0;
        char poscur[maxa + maxb + 1];
        int min = 0;
        printf("Case %d: ", kase++);
        for (int i = 0; i < n; i++){
            scanf("%d %d %d", &init[i][0], &init[i][1], &init[i][2]);
            init[i][1] += init[i][0];
            if (init[i][2] > init[i][0]) sleepn++;
            poscur[i] = init[i][2] + '0';
        }
        poscur[n] = '\0';
        addpos(posn++, poscur);

        while (sleepn && !repeat){
            int sleep_nxt = 0;
            for (int i = 0; i < n; i++){
                int posstu = poscur[i] - '0';
                if (posstu < init[i][0]) poscur[i] = posstu + 1 + '0';
                else if (posstu == init[i][0]){
                    if (sleepn > n / 2){poscur[i] = posstu + 1 + '0', sleep_nxt++;}
                    else poscur[i] = '1';
                }else if (posstu < init[i][1]){poscur[i] = posstu + 1 + '0', sleep_nxt++;}
                else poscur[i] = '1';
            }
            repeat = addpos(posn++, poscur);
            sleepn = sleep_nxt;
            min++;
        }
        
        if (sleepn) printf("-1\n");
        else printf("%d\n", min + 1);
    }

    return 0;
}