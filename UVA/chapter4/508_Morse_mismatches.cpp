#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <map>
#include <string.h>

using namespace std;

unordered_map<char, string> morse;
unordered_map<string, vector<string> > context;

bool isPrefixOf(const string& a, const string& b){
    return a.size() < b.size() && b.compare(0, a.size(), a) == 0;
}

void solve(const string &m){
    if (context.count(m)){
        const vector<string> v = context[m];
        cout << v.front();
        if (v.size() > 1) cout << "!";
        cout << endl;
        return;
    }

    map<int, string> ans;
    for (const auto& p: context){
        const string& cm = p.first;
        if (isPrefixOf(m, cm)) ans[cm.size() - m.size()] = p.second.front();
        else if (isPrefixOf(cm, m)) ans[m.size() - cm.size()] = p.second.front();
    }

    cout << ans.begin()->second << "?" << endl;
}

int main(){
    string C, M;
    while (cin >> C && C != "*"){
        cin >> M;
        morse[C[0]] = M;
    }

    while (cin >> C && C != "*"){
        M.clear();
        for (auto c : C) M += morse[c];
        context[M].push_back(C);
    }

    while (cin >> M && M != "*") solve(M);

    return 0;
}