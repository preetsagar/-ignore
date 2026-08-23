#include <bits/stdc++.h>
using namespace std;

#define int long long

int findRev(int n){
    int rev=0;
    while(n){
        int l = n&1;
        rev |= l;
        n >>= 1;
        rev <<= 1;
    }
    rev >>= 1;

    // cout<<"rev= "<<rev<<"\n";
    return rev;
}

int findNum(int len, int offset){
    int ans = 1ll<<(len-1);
    ans |= (offset<<((len)/2));
    // cout<<"ans= "<<ans<<"\n";


    int rev = findRev(ans);
    return ans|rev;
}

signed main() {
    int t; cin>>t; while(t--){
        int n; cin>>n;

        int len=1, count=0;
        while(count < n){
            int noOfEleWithCurrLen = 1ll<<((len-1)/2);
            count += noOfEleWithCurrLen;
            len++;
        }
        len--;
        // cout<<n<<" "<<count<<"\n";
        count -= 1ll<<((len-1)/2);

        int offset = n-count-1;
        // cout<<" len= "<<len<<" offset="<<offset<<"\n";
        cout<<findNum(len, offset)<<"\n";
    }
    return 0;
}