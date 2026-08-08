#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> arr;

int dp[6010];

int solve(int i){
    if(i<0) return 0;
    if(dp[i]!=-1) return dp[i];

    int ans = arr[i][2];
    for(int j=i-1; j>=0; j--){
        if(arr[i][0] > arr[j][0] && arr[i][1] > arr[j][1]){
            ans = max(ans, solve(j) + arr[i][2]);
        }
    }
    return dp[i] = ans;
}

int main() {
    cin>>n;
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++){
        int a,b,c;
        cin>>a>>b>>c;   // l,b,h
        arr.push_back({a, b, c});
        arr.push_back({a, c, b});
        arr.push_back({b, a, c});
        arr.push_back({b, c, a});
        arr.push_back({c, a, b});
        arr.push_back({c, b, a});
    }
    sort(arr.begin(), arr.end());

    int ans = 0;
    for(int i=0; i<(6*n); i++){
        ans = max(ans, solve(i));
    }
    cout<<ans;
    
    return 0;
}