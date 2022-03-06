#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

unordered_map<char, char> lch, rch;
string pre, in;

char build(int l1, int r1, int l2, int r2){
    if (l1  > r1) return 0;
    char root = pre[l1];
    int p = l2;
    while(in[p] != root) p++;
    int cnt = p - l2;
    lch[root] = build(l1 + 1, l1 + cnt, l2, p - 1);
    rch[root] = build(l1 + cnt + 1, r1, p + 1, r2);
    return root;
}

void postOrder(char root){
    if (lch[root]) postOrder(lch[root]);
    if (rch[root]) postOrder(rch[root]);
    cout << root;
}

int main(){
    while (cin >> pre >> in){
        char r = build(0, pre.length(), 0, in.length());
        postOrder(r);
        cout << endl;
    }
}
