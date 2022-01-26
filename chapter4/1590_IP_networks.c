#include <stdio.h>
#include <math.h>

int addrs[1000][4];

void get_bi(int a, int bi[8]){
    int i = 0;
    while (a){
        bi[i++] = a % 2;
        a /= 2;
    }

    for (int j = i; j < 8; j++)
        bi[j] = 0;
}

int is_equal(int a, int b, int max){
    int abi[8], bbi[8];
    get_bi(a, abi);
    get_bi(b, bbi);

    for (int i = 7; i > 7 - max; i--){
        if (abi[i] != bbi[i]) return 0;
    }

    return 1;
}

int bi_to_d(int bi[8], int max){
    int ret = 0;
    for (int i = 7; i > 7 - max; i--){
        if (!bi[i] && !i) continue;
        ret += pow(bi[i] * 2, i);
    }
    return ret;
}

int main(){

    int m;
    int num = 1;

    while (scanf("%d", &m) != EOF){
        int dif = 0;
        int index = 3;
    
        for (int i = 0; i < m; i++)
            scanf("%d.%d.%d.%d", &addrs[i][3], &addrs[i][2], &addrs[i][1], &addrs[i][0]);
        
        while (!dif && index > -1){        
            int addr = addrs[0][index];
            for (int i = 1; i < m; i++){
                if (addrs[i][index] != addr){
                    dif = 1;
                    break;
                }
            }
            index--;
        }
        index++;

        int max = 8;
        int all_equal = 0;
        int sample;
        while (!all_equal && max > -1){
            all_equal = 1;
            sample = addrs[0][index];
            for (int i = 1; i < m; i++){
                if (!is_equal(sample, addrs[i][index], max)){
                    all_equal = 0;
                    break;
                }
            }

            if (!all_equal) max--;
        }

        int nt_addr[4];
        int nt_mask[4];

        for (int i = 3; i > index; i--){
            nt_addr[i] = addrs[0][i];        
            nt_mask[i] = 255;
        }

        if (max){
            int mask[8];
            get_bi(addrs[0][index], mask);
            nt_addr[index] = bi_to_d(mask, max);
            
            for (int i = 7; i > -1; i--)
                mask[i] = i > 7 - max ? 1 : 0;
            nt_mask[index] = bi_to_d(mask, max);

            for (int i = index - 1; i > -1; i--){
                nt_addr[i] = 0;
                nt_mask[i] = 0;
            }
        }else{
            for (int i = index; i > -1; i--){
                nt_addr[i] = 0;
                nt_mask[i] = 0;
            }
        }
        
        
        printf("%d.%d.%d.%d\n", nt_addr[3], nt_addr[2], nt_addr[1], nt_addr[0]);
        printf("%d.%d.%d.%d\n", nt_mask[3], nt_mask[2], nt_mask[1], nt_mask[0]);
        num++;
    }

    return 0;
}