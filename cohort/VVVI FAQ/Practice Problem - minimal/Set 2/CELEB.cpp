
#include <bits/stdc++.h>
using namespace std;


int FindCeleb(vector<vector<int>> &a)
{
    int n = a.size();
    // stack<int> stk;
    // for(int i=1; i<=n; i++) stk.push(i);

    // while(stk.size()>1){
    //     int p1,p2;
    //     p1 = stk.top(); stk.pop();
    //     p2 = stk.top(); stk.pop();

    //     if(a[p1-1][p2-1]) stk.push(p2);
    //     else stk.push(p1);
    // }

    // int ans = stk.top();
    // int t = stk.top();
    // for(int i=0; i<n; i++){
    //     if(a[t-1][i]) ans=-1;
    // }
    // return ans;

    int celebrity=1;
    for(int i=2; i<=n; i++){
        if(a[i-1][celebrity-1]==0){
            celebrity = i;
        }
    }
    int ans = celebrity;
    for(int i=0; i<n; i++){
        if(a[celebrity-1][i]) ans=-1;
    }
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << FindCeleb(a) << '\n';
}
