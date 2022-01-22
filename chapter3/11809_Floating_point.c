#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    const double EPS = 1e-6;
    char num[100];    

    scanf("%s", num);

    while (strcmp(num, "0e0") != 0){
        double A, v;
        int B;        
        *strchr(num ,'e') = ' ';
        sscanf(num, "%lf%d", &A, &B);
        v = log10(A) + B;

        for (int M = 1; M <= 10; M++){
            int E = round(log10((v + M * log10(2) - log10(pow(2, M) - 1)) / log10(2) + 1) / log10(2));
            if (fabs(((1 << E) - 1) * log10(2) + log10(pow(2, M) - 1) - M * log10(2) - v) <= EPS){
                printf("%d %d\n", M - 1, E);
                break;
            }
        }
        scanf("%s", num);
    }

    return 0;
}