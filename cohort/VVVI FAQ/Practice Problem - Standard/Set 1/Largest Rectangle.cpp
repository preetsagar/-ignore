#include <bits/stdc++.h>
using namespace std;

#define int long long

int t,n;
vector<int> arr,nse,pse;

int solve(){
    for(int i=0; i<n; i++){
        pse[i] = i-1;
        while(pse[i]!=-1 && arr[i] <= arr[pse[i]]) pse[i] = pse[pse[i]];
    }
    for(int i=n-1; i>=0; i--){
        nse[i] = i+1;
        while(nse[i]!=n && arr[i] <= arr[nse[i]]) nse[i] = nse[nse[i]];
    }
    
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, arr[i]*(nse[i]-pse[i]-1));
    }
    return ans;
}

signed main() {
    cin>>t; while(t--){
        cin>>n;
        arr.resize(n);
        nse.resize(n);
        pse.resize(n);

        for(int i=0; i<n; i++) cin>>arr[i];

        cout<<solve()<<"\n";
    }
    return 0;
}