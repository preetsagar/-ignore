#include <bits/stdc++.h>
using namespace std;


int FindRepeated(vector<int> &a)
{
    int n=a.size();
    int ans = 0;
    for(int i=1; i<n; i++) ans ^= i;
    for(int i=0; i<n; i++) ans ^= a[i];

    return ans;
}


int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << FindRepeated(a) << "\n";
}
