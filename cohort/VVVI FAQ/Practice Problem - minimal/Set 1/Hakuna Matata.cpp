#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int grid[1100][1100];
map<int, int> row, col;

int main() {
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>grid[i][j];
        }
    }
    for(int i=1; i<=n; i++) row[i]=i;
    for(int i=1; i<=m; i++) col[i]=i;

    while(k--){
        int a,b;
        char ch; cin>>ch>>a>>b;
        if(ch=='r'){
            int t = row[a];
            row[a]=row[b];
            row[b]=t;
        }
        else if(ch=='c'){
            int t = col[a];
            col[a]=col[b];
            col[b]=t;
        }
        else{
            int x=row[a],y=col[b];
            cout<<grid[x][y]<<"\n";
        }
    }
    return 0;
}