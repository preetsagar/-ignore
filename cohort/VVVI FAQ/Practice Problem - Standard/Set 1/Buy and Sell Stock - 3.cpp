
#include <bits/stdc++.h>
using namespace std;

#define int long long

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve(vector<int> &a, vector<int> &arr){
    int mn = a[0];
    int ans=0;
    for(int i=0; i<a.size(); i++){
        ans = max(ans, a[i]-mn);
        mn = min(mn, a[i]);
        arr[i] = ans;
    }
}

void solve2(vector<int> &a, vector<int> &arr){
    int mx = a[a.size()-1];
    int ans=0;
    for(int i=a.size()-1; i>=0; i--){
        ans = max(ans, mx-a[i]);
        mx  = max(mx, a[i]);
        arr[i] = ans;
    }
}

long long BuyAndSellStock(vector<int> &a) 
{
    int n=a.size();
    vector<int> left(n+1, 0), right(n+1,0);

    solve(a, left);
    solve2(a, right);

    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, left[i] + right[i+1]);
    }
    return ans;
}


signed main(){
   IOS
   
   int t;
   cin>>t;
   
   while(t--){
       int n;
       cin>>n;
       
       vector<int> a(n);

       for (int i = 0; i < n; ++i) {
           cin>>a[i];
       }
       
       cout << BuyAndSellStock(a) << "\n";
   }

   return 0;
}
