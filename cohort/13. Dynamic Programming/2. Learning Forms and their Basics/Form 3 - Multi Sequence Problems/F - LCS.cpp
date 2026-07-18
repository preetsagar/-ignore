#include<bits/stdc++.h>
using namespace std;

#define int long long
string s,t;

int dp[3010][3010], ch[3010][3010];

int solve(int i, int j){
    if(i==s.size() || j==t.size()){
        return 0;
    }
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int ans = 0;
    if(s[i]==t[j]){
        if(ans < 1ll + solve(i+1, j+1)){
            ans = 1ll + solve(i+1, j+1);
            ch[i][j] = 1;
        }
    }
    if(ans < solve(i+1, j)){
        ans = solve(i+1, j);
        ch[i][j] = 2;
    }
    if(ans < solve(i, j+1)){
        ans = solve(i, j+1);
        ch[i][j] = 3;
    }
    
    return dp[i][j] = ans;
}

string printLCS(int i, int j){
    if(i==s.size() || j==t.size()){
        return "";
    }
    
    if(ch[i][j]==1){
        return s[i] + printLCS(i+1, j+1);
    }
    if(ch[i][j]==2){
        return printLCS(i+1, j);
    }
    if(ch[i][j]==3){
        return printLCS(i, j+1);
    }
}

signed main(){
  cin>>s>>t;
  memset(dp, -1, sizeof(dp));
  solve(0,0);
  cout<<printLCS(0, 0);
  return 0;
}