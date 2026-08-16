#include <bits/stdc++.h>
using namespace std;

#define int long long

int t,n,m;
int grid[210][210];
int temp[210];

int kadane(){
    int sum=temp[0];
    int ans=temp[0];
    // dp[i] = max subattay sum ending at i,
    // ya to alone ya to ye piche vale ke sath attach hoga
    for(int j=1; j<m; j++){
        sum = max(temp[j], sum + temp[j]);
        ans = max(ans, sum);
    }

    return ans;
}

signed main() {
    int t; cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }
        int ans=-1e18;
        for(int i=0; i<n; i++){
            for(int k=i; k<n; k++){
                if(i==k){
                    for(int j=0; j<m; j++){
                        temp[j] = grid[k][j];
                    }
                }
                else{
                    for(int j=0; j<m; j++){
                        temp[j] += grid[k][j];
                    }
                }
                // for(int i=0; i<m; i++) cout<<temp[i]<<" "; cout<<"\n";
                ans = max(ans, kadane());
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}