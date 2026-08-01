
#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


long long BuyAndSellStock(vector<int> &a) 
{
    long long ans=0;
    for(int i=1; i<a.size(); i++){
        if(a[i]>a[i-1]){
            ans += a[i]-a[i-1];
        }
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
