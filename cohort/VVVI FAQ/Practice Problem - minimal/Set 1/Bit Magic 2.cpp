#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t; cin>>t;while(t--){
        int n; cin>>n;
        bitset<64> bits(n);
        for(int i=63; i>=0; i--) cout<<bits[i]; cout<<"\n";

        int msb=-1;
        for(int i=63; i>=0; i--){
            if(bits[i]){
                msb=i;
                break;
            }
        }
        cout<<msb<<"\n";

        int lsb=-1;
        for(int i=0; i<64; i++){
            if(bits[i]){
                lsb=i;
                break;
            }
        }
        cout<<lsb<<"\n";

        int powOfTwo=0;
        for(int i=1; i<64; i++){
            if((1ll<<i)==n){
                // cout<<"pow "<<(1ll<<i)<<" ("<<i<<") ";
                powOfTwo=1;
                break;
            }
        }
        cout<<powOfTwo<<"\n";
        
        if(n==0) cout<<-1<<"\n";
        else cout<<(1ll<<lsb)<<"\n";

        for(int i=1; i<64; i++){
            if((1ll<<i) >= n){
                cout<<(1ll<<i)<<"\n";
                break;
            }
        }
    }
    return 0;
}

// 101