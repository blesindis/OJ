#include <stdio.h>

char s1[10000], s2[10000];

int main(){

    while((scanf("%s %s", s1, s2)) != EOF){
        int i1 = 0, i2 = 0;

        while (s1[i1] != '\0' && s2[i2] != '\0'){
            if (s1[i1] == s2[i2]){
                i1++;
                i2++;
            }else{
                i2++;
            }
        }

        if (s1[i1] == '\0')
            printf("Yes\n");
        else    
            printf("No\n");
    }

    return 0;
}