#include <bits/stdc++.h>
using namespace std;

int dp[100010][110];
int solve(vector<int> &arr, int sum, int i){
    if(sum<0) return 0;

    if(i==arr.size()){
        return sum==0;
    }

    if(dp[sum][i]!=-1) return dp[sum][i];

    int ans=0;
    ans |= solve(arr, sum, i+1);
    ans |= solve(arr, sum-arr[i], i+1);

    return dp[sum][i] = ans;
}

void getSubset(vector<int> &arr, int sum, int i, vector<int> &ans){
    if(sum<0) return;
    if(i==arr.size()) return;

    if(solve(arr, sum-arr[i], i+1)){
        ans.push_back(i);
        getSubset(arr, sum-arr[i], i+1, ans);
    }else{
        getSubset(arr, sum, i+1, ans);
    }
}

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    memset(dp, -1, sizeof(dp));
    vector<vector<int>> ans;
    for(int q:queries){
        int isPossible = solve(arr, q, 0);
        vector<int> curAns;
        if(isPossible) getSubset(arr, q, 0, curAns);
        else curAns.push_back(-1);

        // for(int i:curAns) cout<<i<<" "; cout<<"\n";
        ans.push_back(curAns);
    }
    
    return ans;
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        long long sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}