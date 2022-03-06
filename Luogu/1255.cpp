#include<iostream>
using namespace std;

const int maxn = 5003;

int methods = 0;
int n;

int f[maxn][maxn];

int stair(int cur){
    if (cur == 2) return 2;
    if (cur == 1) return 1;
    return stair(cur-1) + stair(cur - 2);
}

int main(){
    cin >> n;
    f[0][0] = 1;
    f[1][0] = 1;

    for (int i = 2; i <= n; i++){
        for (int j = 0; j < maxn; j++)
            f[i][j] = f[i - 1][j] + f[i - 2][j];
        for (int j = 0; j < maxn; j++){
            while(f[i][j] > 9){
                f[i][j] -= 10;
                f[i][j+1]++;
            }
        }
    }

    bool start = false;
    for (int i = maxn - 1; i >= 0; i--){
        if (!start && !f[n][i]) continue;
        start = true;
        cout << f[n][i];
    }
}