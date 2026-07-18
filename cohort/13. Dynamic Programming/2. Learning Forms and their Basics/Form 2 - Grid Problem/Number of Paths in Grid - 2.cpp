#include <bits/stdc++.h>
using namespace std;

#define int long long

int t, n, m, k;
int mat[210][210];
int dp[210][210][410];
int mod=1e9+7;

int solve(int i, int j, int k){
    if(i<0 || j<0 || k<0) return 0;

    if(i==0 && j==0){
        if(mat[i][j]==1) return k>0;
        return 1;
    }

    if(dp[i][j][k]!=-1) return dp[i][j][k];

    int ans=0;
    if(mat[i][j]==0){
        ans = (ans + solve(i-1, j, k) + solve(i, j-1, k))%mod;
    }else{
        ans = (ans + solve(i-1, j, k-1) + solve(i, j-1, k-1))%mod;
    }

    return dp[i][j][k] = ans;
}

signed main() {
    cin>>t; while(t--){
        cin>>n>>m>>k;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>mat[i][j];
            }
        }
        // memset(dp, -1, sizeof(dp));
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                for (int l=0; l<=k; l++){
                    dp[i][j][l] = -1;
                }
            }
        }
        
        cout<<solve(n-1, m-1, k)<<"\n";
    }
    return 0;
}