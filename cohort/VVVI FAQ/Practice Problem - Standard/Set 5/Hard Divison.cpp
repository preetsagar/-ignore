#include <bits/stdc++.h>
using namespace std;

int divide(long dividend, long divisor) {
    if(dividend==INT_MIN && divisor==-1) return INT_MAX;
    if(dividend==INT_MIN && divisor==1) return INT_MIN;

    long ds = abs(divisor);
    long dd = abs(dividend);

    int ans=0;
    while(dd>=ds){

        int pow=0;
        while(dd >= ds*(1ll<<pow)){
            pow++;
        }
        pow--;
        // cout<<dd<<" "<<ds<<" "<<pow<<" \n";

        ans |= (1<<pow);
        dd -= ds*(1ll<<pow);
    }

    if(dividend < 0 && divisor>0) return -ans;
    if(dividend > 0 && divisor<0) return -ans;
    return ans;
}

int main() {
    int t; cin>>t; while(t--){
        int n,k;cin>>n>>k;
        cout<<divide(n,k)<<"\n";
    }
    return 0;
}