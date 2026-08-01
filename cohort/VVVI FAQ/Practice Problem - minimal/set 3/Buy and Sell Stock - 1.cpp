
#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int BuyAndSellStock(vector<int> &a) 
{
    int mn = a[0];
    int ans = 0;
    for(int i=0; i<a.size(); i++){
        ans = max(ans, a[i]-mn);
        mn = min(mn, a[i]);
    }
    return ans;
}


int main(){
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
