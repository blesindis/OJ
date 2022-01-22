#include <stdio.h>

char seqs[50][1000];

int main(){
    int T;
    int m, n;
    char enter;

    char con_seq[1000];
    int con_err = 0;
    int count[4]; //T G C A

    scanf("%d", &T);

    for (int t = 0; t < T; t++){
        scanf("%d %d", &m, &n);
        scanf("%c", &enter);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                scanf("%c", &seqs[i][j]);
            }
            scanf("%c", &enter);
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < 4; j++)
                count[j] = 0;
            for (int j = 0; j < m; j++){
                switch (seqs[j][i])
                {
                case 'T':
                    count[0]++;
                    break;
                case 'G':
                    count[1]++;
                    break;
                case 'C':
                    count[2]++;
                    break;
                case 'A':
                    count[3]++;      
                    break;          
                default:
                    break;
                }                
            }
            int cur_max = 0;
            for (int j = 1; j < 4; j++){
                if (count[j] >= count[cur_max])
                    cur_max = j;                
            }
            switch (cur_max)
            {
            case 0:
                con_seq[i] = 'T';
                break;
            case 1:
                con_seq[i] = 'G';
                break;
            case 2:
                con_seq[i] = 'C';
                break;
            case 3:
                con_seq[i] = 'A';        
                break;    
            default:
                break;
            }
            for (int j = 0; j < 4; j++){
                if (j != cur_max)
                    con_err += count[j];
            }
        }
        for (int i = 0; i < n; i++){
            printf("%c", con_seq[i]);
        }
        printf("\n%d\n", con_err);
        con_err = 0;
    }

    return 0;
}