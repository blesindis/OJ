#include<iostream>
#include<cmath>
using namespace std;

const int maxn = 10;
const int maxa = 1024;
int h[maxn];
int a[maxa];
int height;

void readh(){
    for(int i = 0; i < height; i++){
        char x;
        int y;
        cin >> x >> y;
        h[i] = y;
    }
}

void readnum(int *n){
    string line;
    cin >> line;
    for(int i = 0; i < line.length(); i++){
        n[i] = line[i] - '0';
    }
}

void VVAs(){
    int num;
    int VVA[maxn];
    cin >> num;
    while(num--){
        int index = 0;
        readnum(VVA);
        for(int i = 0; i < height; i++){
            int add = (VVA[h[i]-1] == 0) ? 0 : pow(2, height-i-1);
            index += add;
        }
        //cout << "index" << index << endl;
        cout << a[index];   
    }
    cout << endl << endl;
}


int main(){
    int kase = 1;
    while(cin >> height && height){
        cout << "S-Tree #" << kase++ << ":" << endl;
        readh();
        readnum(a);
        VVAs();
    }
}