#include<iostream>
using namespace std;

const int maxn = 1000002;
int lcd[maxn], rcd[maxn];
int depth = -1;

void dfs(int node, int d){
    if (lcd[node] == 0 && rcd[node] == 0){
        depth = d > depth ? d : depth;
        return;
    }
    if(lcd[node]) dfs(lcd[node], d+1);
    if(rcd[node]) dfs(rcd[node], d+1);
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> lcd[i] >> rcd[i];
    }
    dfs(1, 1);
    cout << depth;
}