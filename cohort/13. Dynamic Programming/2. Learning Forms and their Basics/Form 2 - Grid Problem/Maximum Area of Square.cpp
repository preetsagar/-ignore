#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int mat[1100][1100];
int dp[1100][1100];

int solve(int i, int j){
    if(i<0 || j<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int ans = 0;
    if(mat[i][j]){
        ans = 1 + min(solve(i-1, j), min(solve(i-1, j-1), solve(i, j-1)));
    }

    return dp[i][j] = ans;
}

int main() {
    cin>>t; while(t--){
        cin>>n>>m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>mat[i][j];
                dp[i][j]=-1;
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans = max(ans, solve(i, j));
            }
        }
        cout<<ans*ans<<"\n";
    }
    return 0;
}