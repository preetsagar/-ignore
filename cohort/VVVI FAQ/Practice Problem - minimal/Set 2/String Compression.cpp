#include <bits/stdc++.h>
using namespace std;

char _find(int r){
    if(r<26) return 'a' + r;
    else if(r<52) return 'A' + (r-26);
    else return '0' + (r-52);
}

int main() {
    long long n; cin>>n;

    string ans;
    while(n){
        int r = n%62;
        ans += _find(r);
        n /= 62;
    }
    reverse(ans.begin(), ans.end());
    cout<<ans;

    return 0;
}