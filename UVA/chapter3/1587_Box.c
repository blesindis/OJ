#include <stdio.h>

int main(){
    int pallets[6][2];
    int num = 0;

    while ((scanf("%d", &pallets[0][0])) != EOF){     
        int impossible = 0;

        for (int i = 1; i < 12; i++){
            scanf("%d", &pallets[i / 2][i % 2]);
        }

        for (int i = 0; i < 6; i++){
            if (pallets[i][0] > pallets[i][1]){
                int temp = pallets[i][0];
                pallets[i][0] = pallets[i][1];
                pallets[i][1] = temp;
            }
        }

        for (int i = 0; i < 6; i++){
            for (int j = 0; j < 5 - i; j++){
                if (pallets[j][0] > pallets[j + 1][0]){
                    int temp0 = pallets[j][0];
                    int temp1 = pallets[j][1];
                    pallets[j][0] = pallets[j + 1][0];
                    pallets[j][1] = pallets[j + 1][1];
                    pallets[j + 1][0] = temp0;
                    pallets[j + 1][1] = temp1;
                }else if (pallets[j][0] == pallets[j + 1][0]){
                    if (pallets[j][1] > pallets[j + 1][1]){
                        int temp0 = pallets[j][0];
                        int temp1 = pallets[j][1];
                        pallets[j][0] = pallets[j + 1][0];
                        pallets[j][1] = pallets[j + 1][1];
                        pallets[j + 1][0] = temp0;
                        pallets[j + 1][1] = temp1; 
                    }
                }
            }
        }

        for (int i = 0; i < 3; i++){
            int p = i * 2;
            if (pallets[p][0] != pallets[p+1][0] || pallets[p][1] != pallets[p + 1][1]){
                impossible = 1;
                break;
            }
        }

        int a = pallets[0][0], b = pallets[4][0], c = pallets[4][1];

        if (pallets[0][0] != a || pallets[0][1] != b){
            impossible = 1;            
        }
        if (pallets[2][0] != a || pallets[2][1] != c){
            impossible = 1;
        }
        if (pallets[4][0] != b || pallets[4][1] != c){
            impossible = 1;
        }

        if (impossible){
            printf("IMPOSSIBLE\n");
        }else{
            printf("POSSIBLE\n");
        }
    }

    return 0;
}