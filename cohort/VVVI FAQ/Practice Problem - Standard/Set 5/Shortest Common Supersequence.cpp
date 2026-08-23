
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int dp[1100][1100];
int solve(string &s1, string &s2, int i, int j){
    if(i==s1.size() || j==s2.size()) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int ans = 0;
    if(s1[i]==s2[j]){
        ans = 1+solve(s1, s2, i+1, j+1);
    }else{
        ans = max(ans, solve(s1, s2, i+1, j));
        ans = max(ans, solve(s1, s2, i, j+1));
    }

    return dp[i][j]=ans;
}

string ShortestCommonSupersequence(string &str1, string &str2) {
    memset(dp, -1, sizeof(dp));
    solve(str1, str2, 0, 0);

    string ans = "";
    int i=0, j=0, k=0;
    while(i<str1.size() && j<str2.size()){
        if(str1[i]==str2[j]){
            ans.push_back(str1[i]);
            i++; j++;
        }else{
            if(solve(str1, str2, i+1, j) > solve(str1, str2, i, j+1)){
                ans.push_back(str1[i]);
                i++;
            }else{
                ans.push_back(str2[j]);
                j++;
            }
        }
    }

    while(i<str1.size()){
        ans.push_back(str1[i]); i++;
    }
    while(j<str2.size()){
        ans.push_back(str2[j]); j++;
    }

    return ans;
}
























void checker() {
    string x, y;
    cin >> x >> y;
    auto s = ShortestCommonSupersequence(x, y);
    cout << s.size() << endl;
    bool f = 1;
    int i = 0, j = 0;
    while (i < x.size() && j < s.size()) {
        if (x[i] == s[j])i++, j++;
        else j++;
    }
    if (i != x.size())f = 0;
    i = 0, j = 0;
    while (i < y.size() && j < s.size()) {
        if (y[i] == s[j])i++, j++;
        else j++;
    }
    if (i != y.size())f = 0;
    cout << f << endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        checker();
        // i++;
    }
    return 0;
}
