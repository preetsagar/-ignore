#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[50][50][50];

int solve(int i, int j, int l){
    if(l==1) return s1[i]==s2[j];

    if(dp[i][j][l]!=-1) return dp[i][j][l];
    int ans=0;
    for(int len=1; len<l; len++){
        // not swap
        ans |= solve(i, j, len) && solve(i+len, j+len, l-len);
        // swap
        ans |= solve(i, j+l-len, len) && solve(i+len, j, l-len);
    }

    return dp[i][j][l]=ans;
}

int main() {
    int t; cin>>t; while(t--){
        memset(dp, -1, sizeof(dp));
        cin>>s1>>s2;
        cout<<(solve(0,0,s1.size())?"Yes":"No")<<"\n";
    }
    return 0;
}