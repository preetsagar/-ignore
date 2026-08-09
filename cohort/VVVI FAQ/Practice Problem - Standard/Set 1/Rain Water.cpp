#include <bits/stdc++.h>
using namespace std;

#define int long long

int t,n;
vector<int> arr,rb,lb;

int solve(){
    int mx=arr[0];
    lb[0]=arr[0];
    for(int i=1; i<n; i++){
        mx = max(mx, arr[i]);
        lb[i] = mx;
    }
    mx=arr[n-1];
    rb[n-1]=arr[n-1];
    for(int i=n-2; i>=0; i--){
        mx = max(mx, arr[i]);
        rb[i] = mx;
    }

    int ans = 0;
    for(int i=1; i<n-1; i++){
        int t = min(lb[i], rb[i]);
        ans += t-arr[i];
    }
    return ans;
}

signed main() {
    cin>>t; while(t--){
        cin>>n;
        arr.resize(n);
        lb.resize(n);
        rb.resize(n);

        for(int i=0; i<n; i++) cin>>arr[i];

        cout<<solve()<<"\n";
    }
    return 0;
}