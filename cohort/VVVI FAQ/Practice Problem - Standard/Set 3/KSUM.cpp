#include <bits/stdc++.h>
using namespace std;

long n,k;
vector<long> arr;

int main() {
    cin>>n>>k;
    arr.resize(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    long sum=0, ans=0;
    map<long, long> m;

    m[0]=-1;
    for(int i=0; i<n; i++){
        sum += arr[i];

        long rem = ((sum % k) + k) % k; 
        if(m.find(rem)!=m.end()){
            ans = max(ans, i-m[rem]);
        }else{
            m[rem]=i;
        }
    }
    cout<<ans;
    return 0;
}