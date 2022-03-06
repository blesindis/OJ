#include<iostream>
#include<cmath>
using namespace std;

const int maxn = 200;
typedef struct country{
    int num;
    int score;
    void operator=(const country &a){
        num = a.num;
        score = a.score;
    }
}country;
country a[maxn];


bool operator < (const country& a, const country& b){
    return a.score < b.score;
}

void print(){
}


int main(){
    int n;
    int cnt;
    cin >> n;
    cnt = pow(2, n);
    for (int i = 0; i < cnt; i++){
        cin >> a[i].score;
        a[i].num = i + 1;
    }

    cnt /= 2;
    while (n > 1){
        for (int i = 0; i < cnt; i++){
            int index1 = i * 2;
            int index2 = index1 + 1;
            a[i] = a[index1] < a[index2] ? a[index2] : a[index1];
            //cout << a[index1].score << "\t" << a[index2].score << endl;
        }
        n--;
        cnt /= 2;
    }
    country nd = a[0] < a[1] ? a[0] : a[1];
    cout << nd.num;
}