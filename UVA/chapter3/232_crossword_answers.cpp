#include <iostream>
#include <iomanip>
using namespace std;

int r, c;
char puz[10][10];
int num[10][10];

void print_puz(int r, int c){
    int origin_width = cout.width();
    int sequential = 0;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (sequential == 1){
                if (puz[i][j] == '*'){
                    sequential = 0;
                    cout << endl;
                }else if (j == c - 1){
                    cout << puz[i][j] << endl;
                    sequential = 0;
                }else{
                    cout << puz[i][j];
                }
            }else{
                if (puz[i][j] != '*'){                        
                    if (num[i][j] == -1){
                        cout << "WARNING: THIS SHOULD BE ELIGIBLE" << endl;
                    }
                    cout << setw(3) << num[i][j];
                    cout << setw(origin_width) << '.' << puz[i][j];
                    if (j == c - 1){
                        cout << endl;
                    }else{
                        sequential = 1;
                    }
                }
            }
        }
    } 
}

int main(){
    int puzzle_num = 1;
    
    cin >> r;
    while (r != 0){
        // handle input 
        if (puzzle_num != 1)
            cout << endl;
        cin >> c;
        
        for (int i = 0; i < r; i++){            
            for (int j = 0; j < c; j++){                
                cin >> puz[i][j];                
            }
        }

        int cur_num = 1;
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                if (i == 0 && puz[i][j] != '*'){
                    num[i][j] = cur_num;
                    cur_num++;
                }else if (j == 0 && puz[i][j] != '*'){
                    num[i][j] = cur_num;
                    cur_num++;
                }else if ((puz[i - 1][j] == '*' || puz[i][j - 1] == '*') && puz[i][j] != '*'){
                    num[i][j] = cur_num;
                    cur_num++; 
                }else{
                    num[i][j] = -1;
                }                     
            }            
        }

        // handle output
        cout << "puzzle #" << puzzle_num << ":" << endl;
        cout << "Across" << endl;

        print_puz(r, c);
        
        int sequential = 0;
        int origin_width = 0;
        cout << "Down" << endl;
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                if ((i == 0 || puz[i - 1][j] == '*') && puz[i][j] != '*'){
                    cout << setw(3) << num[i][j] << '.' << setw(origin_width);
                    for (int row = i; row < r && puz[row][j] != '*'; row++)
                        cout << puz[row][j];
                    cout << endl;
                }
            }
        }

        puzzle_num++;
        cin >> r;
    }
}
