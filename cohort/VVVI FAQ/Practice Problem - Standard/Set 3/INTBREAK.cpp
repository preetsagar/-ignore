
#include <bits/stdc++.h>
using namespace std;

// for small constraint use DP

long mod = 1e9+7;

long power(int a, int b){
    if(b==0) return 1;
    if(b%2==0){
        long t = power(a, b/2);
        return (t*t)%mod;
    }else{
        return (a * power(a, b-1))%mod;
    }
}

int findMaxProd(long n)
{
    if(n==2) return 1;
    if(n==3) return 2;

    if(n%3==0){
        return power(3,n/3);
    }else if(n%3==1){
        return power(3,(n/3)-1)*4%mod;
    }else{
        return power(3,n/3)*2%mod;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << findMaxProd(n) << '\n';
    }
    return 0;
}
