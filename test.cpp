#include<stdio.h>
#include<ctype.h>
#include<cstring>
#include<stdlib.h>

int main(){

#ifdef FREOPEN
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T = 0;

    scanf("%d", &T);

    while (T--){
        char line[100];
        int min_period = 0;

        getchar();
        scanf("%s", line);

        for (int i = 0; i < strlen(line); i++){
            min_period = i + 1;
            int wrong = 0;

            if (strlen(line) % min_period)
                continue;

            for (int j = i + 1; j < strlen(line); j++){
                if (line[j % (i + 1)] != line[j])
                {
                    wrong = 1;
                    break;
                }
            }
            if (! wrong)
                break;
        }

        if (T)
            printf("%d\n\n", min_period);
        else
            printf("%d", min_period);
    }

    return 0;
}