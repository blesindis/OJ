#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 10000;

int main(){

    int n, q, x, a[maxn], kase = 1;
    while(scanf("%d %d", &n, &q) == 2 && n){
        printf("CASE# %d:\n", kase++);
        for(int* i = a; i < a + n; i++)
            scanf("%d", i);
        sort(a, a+n);
        for(int i = 0; i < q; i++){
            scanf("%d", &x);
            int p = lower_bound(a, a+n, x) - a;
            if(p < n && a[p] == x) 
                printf("%d found at %d\n", x, p + 1);
            else
                printf("%d not found\n", x);
        }
    }

    return 0;
}