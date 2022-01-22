#include <stdio.h>

int remainders[10000];
int decimals[10000];

int main(){
    int numer, denomi;
    int remainder;
    int deci_num = 0, rem_num = 0;
    int cyc_start = 0, cyc_end = 0;
    int isrepeat = 0;

    while((scanf("%d %d", &numer, &denomi)) != EOF){
        remainder = numer;
        deci_num = 0;
        rem_num = 0;
        isrepeat = 0;

        do{
            int temp = remainder;
            remainder = remainder % denomi;            
            remainders[rem_num] = remainder;
            rem_num++;
            decimals[deci_num] = temp / denomi;
            deci_num++;

            if (rem_num > 1){
                for (int i = 0; i < rem_num - 1; i++){
                    if (remainder == remainders[i]){
                        cyc_start = i;
                        isrepeat = 1;
                        break;
                    }
                }
            }
        
            remainder *= 10;

        }while (rem_num == 1 || !isrepeat);
        cyc_end = deci_num - 1;

        printf("%d/%d = %d.", numer, denomi, decimals[0]);

        if (deci_num <= 50){
            for (int i = 1; i < 51; i++){
                if (i == cyc_start + 1){
                    printf("(");
                }
                printf("%d", decimals[i]);
                if (i == cyc_end){
                    printf(")");
                    break;
                }
            }
        }else{
            for (int i = 1; i < 51; i++){
                if (i == cyc_start + 1){
                    printf("(");
                }
                printf("%d", decimals[i]);
                if (i == 50){
                    printf("...)");
                }
            }
        }
        printf("\n   ");
        printf("%d = number of digits in repeating cycle\n\n", cyc_end - cyc_start);
    }

    return 0;
}