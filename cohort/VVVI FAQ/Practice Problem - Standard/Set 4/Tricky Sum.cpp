#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--){
        int a,b; cin>>a>>b;
        while(b){
            int carry = (a&b)<<1;
            a = a^b;
            b = carry;
        }
        cout<<a<<'\n';
    }
    return 0;
}