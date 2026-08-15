#include <bits/stdc++.h>
using namespace std;

long n,m;

int mod = 1e9+7;

int main() {
    cin >> n >> m;

    long long total = (n * m % mod) * ((n * m - 1) % mod) % mod;
    long long danger = 0;

    if(n >= 2 && m >= 3)
        danger += 4LL * (n - 1) * (m - 2);

    if(n >= 3 && m >= 2)
        danger += 4LL * (n - 2) * (m - 1);

    cout << ((total - danger) % mod + mod) % mod;
    return 0;
}