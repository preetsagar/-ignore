
#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>> &a, int mid, int k){
    int count=0;
    for(int i=0; i<a.size(); i++){
        count += upper_bound(a[i].begin(), a[i].end(), mid)-a[i].begin();
    }
    return count>=k;
}

int MedianInMatrix(vector<vector<int>> &a)
{
    int l=1, r=1000000, ans=-1;
    int k = ((a.size())*(a[0].size()))/2 + 1;
    while(l<=r){
        int mid = (l+r)/2;
        if(check(a, mid, k)){
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
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    cout << MedianInMatrix(a) << "\n";

    return 0;
}
