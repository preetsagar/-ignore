#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--){
        int n; cin>>n;
        // int ans=0;
        // for(int i=0; i<32; i+=2){
        //     int even = n&(1<<i);
        //     int odd  = n&(1<<(i+1));

        //     if(odd) ans += (1<<i);
        //     if(even) ans += (1<<(i+1));
        // }
        // cout<<ans<<"\n";

        int even_mask = 0xAAAAAAAA;
        int odd_mask  = 0x55555555;
        int ans=0;

        int even = n & even_mask;
        int odd  = n & odd_mask;

        ans += (odd<<1);
        ans += (even>>1);
        cout<<ans<<"\n";
    }
    return 0;
}