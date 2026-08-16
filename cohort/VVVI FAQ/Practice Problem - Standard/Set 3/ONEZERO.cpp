
#include <bits/stdc++.h>
using namespace std;

int dp[110][110][110];

int solve(vector<string> &v, int x, int y, int i){
    if(x<0 ||y<0) return -1e9;
    if(i==v.size()){
        return x>=0 && y>=0 ? 0 : -1e9;
    }

    if(dp[x][y][i]!=-1) return dp[x][y][i];

    int ans = 0;
    ans = max(ans, solve(v,x,y,i+1));
    int cnt0 = 0, cnt1=0;
    for(int j=0; j<v[i].size(); j++){
        if(v[i][j]=='0') cnt0++;
        else cnt1++;
    }
    ans = max(ans, (1+solve(v,x-cnt0,y-cnt1, i+1)));

    return dp[x][y][i] = ans;
}

int findMaxSubset(vector<string> &v, int x, int y)
{
    memset(dp, -1, sizeof(dp));
    return solve(v, x, y, 0);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x, y;
    cin >> n >> x >> y;
    vector<string> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    cout << findMaxSubset(v, x, y) << '\n';
    return 0;
}
