#include <bits/stdc++.h>
using namespace std;

#define int long long

int MaxVials(vector<pair<int, int>> &a, int m)
{
    sort(a.begin(), a.end(), [](auto &x, auto &y) {
        return x.second > y.second;
    });

    int ans = 0;

    for(auto [boxes, vials] : a){
        if(m == 0)
            break;

        int take = min(m, boxes);

        ans += take * vials;
        m -= take;
    }

    return ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }

    cout << MaxVials(a, m) << '\n';

    return 0;
}