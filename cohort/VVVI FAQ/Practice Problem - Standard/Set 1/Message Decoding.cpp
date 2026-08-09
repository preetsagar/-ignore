#include <bits/stdc++.h>
using namespace std;

#define int long long

string s;
int n;
int dp[100010];
int mod = 1e9+7;

int solve(int i){
    if(i<0) return 1;
    if(dp[i]!=-1) return dp[i];

    int ans = 0;
    if(s[i]!='0'){
        ans += solve(i-1);
    }
    if(i>0){
        int x= (s[i]-'0') + (s[i-1]-'0')*10;
        if(x>9 && x<27){
            ans += solve(i-2);
        }
    }
    return dp[i]=ans%mod;
}

signed main() {
    cin>>s;
    memset(dp, -1, sizeof(dp));
    n = s.size();
    cout<<solve(n-1);
    return 0;
}