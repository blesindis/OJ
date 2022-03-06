#include<iostream>
#include<map>
#include<algorithm>
#include<queue>

using namespace std;

typedef struct Grid{
    int c;
    int r;
    int d;
    Grid(int c=0, int r=0, int d=0):c(c), r(r), d(d){}
}Grid;

struct cmp{
    bool operator()(Grid g1, Grid g2) const{
        if (g1.c != g2.c) return g1.c < g2.c;
        if (g1.r != g2.r) return g1.r < g2.r;
        return false;
    }
};


int c1, c2, r2;
int min_step;
int m[8][2] = {{1,2}, {1,-2}, {2,1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
map<Grid, int, cmp> path;


bool inBorder(int c, int r){
    if (c > 8 || c < 1 || r > 8 || r < 1) return false;
    return true;
}

int move(int c, int r, int step, queue<Grid> grid_queue){
    //cout << "enter";
    
    Grid cur(c, r, 0);
    grid_queue.push(cur);
    path[cur] = 1;
    step = 0;
    while(1){
        Grid cur_grid = grid_queue.front();
        if(cur_grid.c == c2 && cur_grid.r == r2) return cur_grid.d;
        for(int i = 0; i < 8; i++){
            Grid new_grid(cur_grid.c + m[i][0], cur_grid.r + m[i][1], cur_grid.d + 1);
            if(path.count(new_grid)) continue;
            if(!inBorder(new_grid.c, new_grid.r)) continue;
            grid_queue.push(new_grid);
            path[new_grid] = 1;
        }
        grid_queue.pop();
    }
    
}

int main(){
    char col1, col2;
    int r1;
    while(cin >> col1 >> r1 >> col2 >> r2){
        cout << "To get from " << col1 << r1 << " to " << col2 << r2 << " takes ";
        c1 = col1 - 'a' + 1;
        c2 = col2 - 'a' + 1;
        path.clear();
        queue<Grid> grid_queue;
        min_step = move(c1, r1, 0, grid_queue);
        
        cout << min_step << " knight moves." << endl;
        
    }
    return 0;
}