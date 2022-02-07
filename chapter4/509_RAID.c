#include <stdio.h>
#include <string.h>
#include <math.h>
#include <memory.h>

const int maxd = 10, maxs = 64, maxb = 105;
char data[maxd][maxs * maxb], message[maxd * maxs * maxb];
int c, p, d, s, b;

int readint(int i, int n){
    int v = 0;
    while (n--) v = v * 2 + message[i++] - '0';
    return v;
}

int main(){
    int num = 1;
    while(scanf("%d%d%d", &d, &s, &b) == 3 && d){
        int len = s * b;
        char oe[2];
        scanf("%s", oe);
        p = (oe[0] == 'E' ? 0 : 1); 

        for (int i = 0; i < d; i++){
            scanf("%s", data[i]);
        }
        printf("Disk set %d is ", num);
        int valid = 1;
        for (int i = 0; valid && i < len; i++){
            int res, mis = 0, cnt = 0;
            while (data[cnt][i] == 'x' && cnt < d){mis = cnt, cnt++;}
            if (cnt < d){
                res = data[cnt][i] - '0';
                for (int j = cnt + 1; j < d; j++){
                    if (data[j][i] != 'x') res ^= data[j][i] - '0';
                    else {mis = j, cnt++;}
                }
            }
            if (cnt > 1 || (!cnt && res != p)) valid = 0;
            else if (cnt == 1) data[mis][i] = (res ^ p) + '0';
        }

        if (!valid) printf("invalid.\n");
        else{
            printf("valid, contents are: ");
            int cnt = 0;
            for (int i = 0; i < len; i += s){
                for (int j = 0; j < d; j++){
                    if ((i / s) % d != j){
                        for (int k = 0; k < s; k++) message[cnt++] = data[j][i + k];
                    }
                }
            }
            while (cnt % 4) message[cnt++] = '0';
            for (int i = 0; i < cnt; i += 4){
                printf("%X", readint(i, 4));
            }
            printf("\n");
        }
        num++;
    }

    return 0;
}