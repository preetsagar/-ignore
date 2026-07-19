#include <bits/stdc++.h>
using namespace std;

int n;
int arr[510], prefixSum[510];
int mod = 100;

int dp[510][510];

int cost(int l, int m, int r){
    int ll = (prefixSum[m]-prefixSum[l-1])%mod;
    int rr = (prefixSum[r]-prefixSum[m])%mod;

    return (ll * rr);
}

int solve(int l, int r){
    if(l>r) return 0;
    if(l==r) return 0;

    if(dp[l][r]!=-1) return dp[l][r];

    int ans = 1e9;
    for(int i=l; i<r; i++){
        ans = min(ans, solve(l, i) + solve(i+1, r) + cost(l,i,r));
    }

    return dp[l][r] = ans;
}

signed main() {
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        prefixSum[i] = prefixSum[i-1]+arr[i];
    }
    memset(dp, -1, sizeof(dp));
    cout<<solve(1, n);

    return 0;
}