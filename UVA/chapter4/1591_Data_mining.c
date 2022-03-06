#include <stdio.h>

long n, sp, sq;

int main(){
    while (scanf("%ld %ld %ld", &n, &sp, &sq) == 3){
        long K = 99999999999;
        int a, b;
        for (int i = 0; i < 32; i++){
            for (int j = 0; j < 32; j++){
                long Q1 = (sp + (sp << i)) >> j;
                if (Q1 < sq) continue;
                long Kcur = ((sp * (n - 1) + (sp * (n - 1) << i)) >> j) + sq;
                if (Kcur < K) {a = i, b = j, K = Kcur;}
            }
        }
        printf("%ld %d %d\n", K, a, b);
    }

    return 0;
}