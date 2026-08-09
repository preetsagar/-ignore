#include <bits/stdc++.h>
using namespace std;

int n;
int skip[10][10];
int vis[10];

int dfs(int u, int l){
    if(l==0) return 1;
    vis[u]=1;

    int ans=0;
    for(int v=1; v<10; v++){
        if(!vis[v] and (skip[u][v] == 0 || vis[skip[u][v]])){
            ans += dfs(v, l-1);
        }
    }
    vis[u] = 0;
    return ans;
}

int main() {
    cin>>n;

    // 1 2 3
    // 4 5 6
    // 7 8 9
    skip[1][3] = skip[3][1] = 2;
    skip[1][7] = skip[7][1] = 4;
    skip[1][9] = skip[9][1] = 5;
    skip[2][8] = skip[8][2] = 5;
    skip[3][7] = skip[7][3] = 5;
    skip[3][9] = skip[9][3] = 6;
    skip[4][6] = skip[6][4] = 5;
    skip[7][9] = skip[9][7] = 8;
    

    int ans=0;
    memset(vis, 0, sizeof(vis));
    for(int i=1; i<10; i++){
        ans += dfs(i, n-1);
    }
    cout<<ans<<"\n";
    return 0;
}