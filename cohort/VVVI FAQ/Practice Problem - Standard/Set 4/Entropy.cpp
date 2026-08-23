#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr(n);

        for(int i=0; i<n; i++) cin>>arr[i];
        sort(arr.begin(), arr.end());

        int ans = (arr[n-1]) - (arr[0]);

        for(int i=1; i<n; i++){
            int possibleMn = min(arr[i]-k, arr[0]+k);
            int possibleMx = max(arr[i-1]+k, arr[n-1]-k);

            ans = min(ans, possibleMx-possibleMn);
        }
        cout<<ans<<"\n";
    }
    return 0;
}