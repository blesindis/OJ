#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <math.h>
using namespace std;

typedef struct aFree{
    void *next;
}Free;

int main(){
    
    double a = 0.199999999999999;
    double b = 0.5;
    for (int i = 0; i < 15; i++){
        b = b * 10;
    }

    printf("%lf", b);

    return 0;
}