
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &a, vector<int> &b, int k, int mid){
    int count = 0;
    count += upper_bound(a.begin(), a.end(), mid) - a.begin();
    count += upper_bound(b.begin(), b.end(), mid) - b.begin();

    return count >= k;
}

int KthElement(vector<int> &a, vector<int> &b, int k)
{
    int l=1, r=1e6;
    int mid,ans;
    while(l<=r){
        mid = (l+r)/2;
        if(check(a, b, k, mid)){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> a(n), b(m);
    
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < m; i++)
        cin >> b[i];
    
    cout << KthElement(a, b, k) << '\n';

    return 0;
}
