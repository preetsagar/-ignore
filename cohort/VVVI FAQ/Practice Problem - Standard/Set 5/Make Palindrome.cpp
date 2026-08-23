#include <bits/stdc++.h>
using namespace std;

string s;
int dp[1100][1100];

int solve(int i, int j){
    if(i>=j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int ans = 1e9;
    if(s[i]==s[j]){
        ans = solve(i+1, j-1);
    }else{
        ans = min(ans, 1 + solve(i+1, j));
        ans = min(ans, 1 + solve(i, j-1));
    }

    return dp[i][j]=ans;
}

int main() {
    int t; cin>>t; while(t--){
        memset(dp, -1, sizeof(dp));
        cin>>s;
        cout<<solve(0, s.size()-1)<<"\n";
    }
    return 0;
}