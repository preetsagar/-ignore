#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
vector<int> arr;
int dp[100010];

// Space Optimization
// ll dp[n][2];
// dp[0][0] = a[0], dp[0][1] = 0;
// for (int i = 1; i < n; i++)
// {
//     dp[i][0] = a[i] + dp[i - 1][1];
//     dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
// }
// cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';

int solve(int i){
    if(i>=n) return 0;

    if(dp[i]!=-1) return dp[i];

    int ans = -1e18;
    ans = max(ans, solve(i+1));
    ans = max(ans, arr[i] + solve(i+2));

    return dp[i] = ans;
}

signed main() {
    cin>>n;
    for(int i=0; i<n; i++){
        int t; cin>>t;
        arr.push_back(t);
    }
    memset(dp, -1, sizeof(dp));
    cout<<solve(0);
    return 0;
}