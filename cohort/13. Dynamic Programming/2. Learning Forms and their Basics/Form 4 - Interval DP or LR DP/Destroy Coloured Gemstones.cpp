#include <bits/stdc++.h>
using namespace std;

int t,n;
int arr[110];
int dp[100][110];

int solve(int l, int r){
    if(l>r) return 0;
    if(l==r) return 1;

    if(dp[l][r]!=-1) return dp[l][r];

    int ans = 1e9;
    ans = min(ans, 1+solve(l+1, r));
    if(arr[l]==arr[l+1]){
        ans = min(ans, 1 + solve(l+2, r));
    }
    for(int i=l+2; i<=r; i++){
        if(arr[i]==arr[l]){
            ans = min(ans, solve(l+1, i-1) + solve(i+1, r));
        }
    }

    return dp[l][r] = ans;
}

int main() {
    cin>>t; while(t--){
        cin>>n;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        cout<<solve(0, n-1)<<"\n";
    }
    return 0;
}