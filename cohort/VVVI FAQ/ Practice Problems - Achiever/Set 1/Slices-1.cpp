
#include <bits/stdc++.h>
using namespace std;


long long findArithmeticSeq(int a[], int n)
{
    long long dp[n+5];
    memset(dp, -1, sizeof(dp));
    dp[0] = dp[1] = 0;

    for(int i=2; i<n; i++){
        if(a[i]-a[i-1]==a[i-1]-a[i-2]){
            dp[i] = dp[i-1]+1ll;
        }else{
            dp[i]=0;
        }
    }

    long long ans=0;
    for(int i=0; i<n; i++) ans += dp[i];
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << findArithmeticSeq(a, n) << '\n';
    return 0;
}
