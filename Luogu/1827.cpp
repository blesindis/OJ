#include<iostream>
#include<map>
#include<cctype>
#include<cstdio>
#include<string>
using namespace std;

const int maxn = 30;
map<char, char> lch, rch;
char pre[maxn], in[maxn];

//l1 for pre order, 2 for in order
char build(int l1, int r1, int l2, int r2){
    if (r1 < l1) return 0;
    char root = pre[l1];
    int p = l2;
    int sz;
    while(in[p] != root) p++;
    sz = p - l2;

    lch[root] = build(l1 + 1, l1 + p - l2, l2, p - 1);
    rch[root] = build(l1 + p - l2 + 1, r1, p + 1, r2);
    return root;
}

void post(char node){
    if (lch.count(node) && lch[node]) post(lch[node]);
    if (rch.count(node) && rch[node]) post(rch[node]);
    cout << node;
}

int main(){
    string s1, s2;
    int i = 0;
    cin >> s1 >> s2;
    for (i = 0; i < s1.length(); i++){
        in[i] = s1[i];
        pre[i] = s2[i];
    }
    char root = build(0, i, 0, i);
    post(root);
}
