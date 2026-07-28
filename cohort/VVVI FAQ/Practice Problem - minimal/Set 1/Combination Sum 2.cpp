
#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

vector<vector<int>> ans;
vector<int> ds;

void solve(int n, int start, int k){
    if(k==0){
        if(n==0){
            ans.push_back(ds);
        }
        return;
    }
    if(n<0) return;

    for(int i=start; i<10; i++){
        ds.push_back(i);
        solve(n-i, i+1, k-1);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum(int k, int n) {
    solve(n, 1, k);
    return ans;
}

void checker() {
    int k, n;
    cin >> k >> n;
    vector<int> t;
    auto v = combinationSum(k, n);
    for (auto &x : v) {
        sort(x.begin(), x.end());
    }
    sort(v.begin(), v.end());
    for (auto x : v) {
        for (auto y : x)cout << y << " ";
        cout << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    while (t--) {
        checker();
    }
    return 0;
}
