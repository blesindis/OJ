#include <stdio.h>

const int maxm = 30, maxn = 30;
int squares[maxm * maxn];
int m, n;
int vol;

int main(){
    int kase = 1;
    while (scanf("%d %d", &m, &n) == 2 && m && n){
        for (int i = 0; i < m * n; i++){
            scanf("%d", &squares[i]);
        }
        for (int i = 0; i < m * n - 1; i++){
            for (int j = 0; j < m * n - i - 1; j++){
                if (squares[j] > squares[j + 1]){
                    int temp = squares[j];
                    squares[j] = squares[j + 1];
                    squares[j + 1] = temp;
                }
            }
        }


        scanf("%d", &vol);
        double v;
        v = vol * 1.0 / 100;

        int i = 0;
        double wl = 0;
        for (i = 0; i < m * n - 1; i++){
            v += squares[i];
            wl = v * 1.0 / (i + 1);
            if (wl <= squares[i + 1]) break;
        }
        if (i == m * n - 1 && wl > squares[i] || i == 0 && m * n - 1 == 0) {
            v += squares[i];
            wl = v * 1.0 / (i + 1);
        }
        printf("Region %d\n", kase++);
        printf("Water level is %.2f meters.\n", wl);
        printf("%.2f percent of the region is under water.\n\n", (i + 1) * 100.0 / (m * n));
    }
    return 0;
}