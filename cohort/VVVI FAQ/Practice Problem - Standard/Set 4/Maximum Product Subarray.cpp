#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t; cin>>t; while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];

        int ans, currMax, currMin;
        ans = currMax = currMin = arr[0];
        for(int i=1; i<n; i++){
            int temp = currMax;
            currMax = max({arr[i], arr[i]*currMax, arr[i]*currMin});
            currMin = min({arr[i], arr[i]*currMin, arr[i]*temp});

            ans = max(ans, currMax);
        }
        cout<<ans<<"\n";
    }
    return 0;
}