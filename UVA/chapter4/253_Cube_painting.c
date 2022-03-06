#include <stdio.h>

int axis16[4] = {2, 4, 5, 3};
int axis34[4] = {2, 1, 5, 6};
int axis25[4] = {1, 3, 6, 4};

int is_same(int axis[4], int step, int comp[4], char s2[6]){
    
    int same = 0;

    for (int i = 0; i < 4; i++){
        int index = i;
        same = 1;
        for (int j = 0; j < 4; j++){
            if (j) index = index + step;
            index = index < 0 ? index + 4 : index;
            index = index % 4;
            if (s2[axis[index] - 1] != comp[j]){
                same = 0;
                break;
            }
        }
        if (same) break;
    }

    return same;
}

int main(){

    char s[15];

    while(scanf("%s", s) != EOF){
        char s1[6], s2[6];
        int same = 0;
        int comp[4];

        for (int i = 0; i < 6; i++){
            s1[i] = s[i];
            s2[i] = s[i + 6];
        }

        for (int i = 0; i < 4; i++){
            comp[i] = s1[axis16[i] - 1];
        }

        if (!same && s1[0] == s2[0] && s1[5] == s2[5])
            same = is_same(axis16, 1, comp, s2);
        if (!same && s1[0] == s2[5] && s1[5] == s2[0])
            same = is_same(axis16, -1, comp, s2);
        if (!same && s1[0] == s2[2] && s1[5] == s2[3])
            same = is_same(axis34, 1, comp, s2);
        if (!same && s1[0] == s2[3] && s1[5] == s2[2])  
            same = is_same(axis34, -1, comp, s2);    
        if (!same && s1[0] == s2[1] && s1[5] == s2[4])
            same = is_same(axis25, 1, comp, s2);
        if (!same && s1[0] == s2[4] && s1[5] == s2[1])
            same = is_same(axis25, -1, comp, s2);
        
        if (same) printf("TRUE\n");
        else printf("FALSE\n");

    }    

    return 0;
}