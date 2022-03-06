#include <stdio.h>
#include <string.h>

int main(){

    char master[100], driven[100];

    while((scanf("%s %s", master, driven)) != EOF){
        int start = 0;
        int length1 = 0, length2 = 0;
        while(master[start] != '\0'){
            int stop = 0;
            // find where double 2 exists
            for (int i = 0; driven[i] != '\0' && master[i + start] != '\0'; i++){
                if (driven[i] == '2' && master[start + i] == '2'){
                    stop = 1;
                    break;
                }                
            }

            if (stop){
                start++;
            }else{
                break;
            }
        }
        if (strlen(driven) > strlen(master) - start)
            length1 = strlen(driven) + start;
        else
            length1 = strlen(master);

        start = 0;
        while(driven[start] != '\0'){
            int stop = 0;
            // find where double 2 exists
            for (int i = 0; master[i] != '\0' && driven[i + start] != '\0'; i++){
                if (master[i] == '2' && driven[start + i] == '2'){
                    stop = 1;
                    break;
                }                
            }

            if (stop){
                start++;
            }else{
                break;
            }
        }
        if (strlen(master) > strlen(driven) - start)
            length2 = strlen(master) + start;
        else
            length2 = strlen(driven);
        
        int length = length1 < length2 ? length1 : length2;        
        printf("%d\n", length);
    }

    return 0;
}