#include <bits/stdc++.h>
using namespace std;

vector<string> grid;

bool check(int i, int j, char n){
    for(int k=0; k<9; k++){
        if(grid[i][k]==n) return false;
    }
    for(int k=0; k<9; k++){
        if(grid[k][j]==n) return false;
    }
    
    int x=i/3 * 3;
    int y=j/3 * 3;
    for(int i=x; i<(x+3); i++){
        for(int j=y; j<(y+3); j++){
            if(grid[i][j]==n) return false;
        }
    }
    return true;
}

bool solve(int i, int j){
    if(i==9) return true;
    if(j==9) return solve(i+1, 0);

    if(grid[i][j]!='.') return solve(i, j+1);
    
    for(char num='1'; num<='9'; num++){
        if(check(i,j, num)){
            grid[i][j] = num;
            if(solve(i, j+1)) return true;
            grid[i][j] = '.';
        }
    }
    return false;
}

int main() {
    for(int i=0; i<9; i++){
        string s; cin>>s;
        grid.push_back(s);
    }
    if(solve(0,0)) for(string i:grid) cout<<i<<"\n";

    return 0;
}