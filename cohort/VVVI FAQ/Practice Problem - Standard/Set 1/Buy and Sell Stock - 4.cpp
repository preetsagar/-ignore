
#include <bits/stdc++.h>
using namespace std;

#define int long long

#define IOS ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);

vector<vector<vector<int>>> dp;

long long solve(vector<int> &a, int k, int hold, int i){
    if(k<0) return -1e18;
    if(i>=a.size()){
        if(k==0) return 0;
        return -1e18;
    }
    if(dp[i][k][hold]!=-1) return dp[i][k][hold];

    long long ans = 0;
    ans = max(ans, solve(a, k, hold, i+1));
    if(hold==0){
        ans = max(ans, solve(a, k, 1, i+1) - a[i]);
    }else{
        ans = max(ans, solve(a, k-1, 0, i+1) + a[i]);
    }

    return dp[i][k][hold] = ans;
}

long long BuyAndSellStock(vector<int> &a, int k){
    int n=a.size();
    k = min(k, n / 2);
    dp.assign(n+5, vector<vector<int>>(k + 5, vector<int>(3, -1)));
    int ans = 0;
    for(int i=0; i<=k; i++){
        ans = max(ans, solve(a, i, 0, 0));
    }
    return ans;
}


signed main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (long long i = 0; i < n; ++i)
            cin >> a[i];

        cout << BuyAndSellStock(a, k) << "\n";
    }
    return 0;
}
