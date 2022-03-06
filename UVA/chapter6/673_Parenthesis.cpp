#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
    string s;
    int n;
    cin >> n;
    getline(cin, s);
    while(n--){
        stack<char> l;
        int i;
        getline(cin, s);
        if(s.empty()) {cout << "Yes" << endl; continue;}
        for(i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[') l.push(s[i]);
            else{
                if(l.empty()) break;
                char pair = l.top();
                if (s[i] == ')' && pair == '(' || s[i] == ']' && pair == '[') l.pop();
                else break;
            }
        }
        if(i == s.size() && l.empty()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}