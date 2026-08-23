#include <bits/stdc++.h>
using namespace std;

int t,n;
string s;
map<string, int> m;

int dp[1010];

int solve(int i){
    if(i<0) return 1;

    if(dp[i]!=-1) return dp[i];

    int ans=0;
    for(int j=i; j>=0; j--){
        string t = s.substr(j, i-j+1);
        if(m.find(t)!=m.end()){
            ans |= solve(j-1);
        }
    }

    return dp[i]=ans;
}


int main() {
    cin>>t; while(t--){
        m.clear();
        memset(dp, -1, sizeof(dp));
        cin>>n>>s;
        for(int i=0; i<n; i++){
            string t; cin>>t;
            m[t]++;
        }

        cout<<(solve(s.size()-1)?"Yes":"No")<<"\n";
    }
    return 0;
}