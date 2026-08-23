#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[1100][1100];
int solve(int i, int j){
    if(i==s1.size()||j==s2.size()) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int ans=0;
    if(s1[i]==s2[j]){
        ans = 1 + solve(i+1, j+1);
    }
    return dp[i][j] = ans;
}

int main() {
    int t; cin>>t; while(t--){
        cin>>s1>>s2;
        int ans=0;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<s1.size(); i++){
            for(int j=0; j<s2.size(); j++){
                ans = max(ans, solve(i,j));
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}