#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) cin>>arr[i];

    int count5=0;
    for(int &i:arr){
        while(i%5==0 && i){
            i = i/5;
            count5++;
        }
    }
    // for(int i:arr) cout<<i<<" "; cout<<endl;

    for(int &i:arr){
        while(i%2==0 && count5>0){
            i = i/2;
            count5--;
        }
    }
    // for(int i:arr) cout<<i<<" "; cout<<endl;

    int ans = 1;
    for(int i:arr){
        ans = (ans * i)%10;
    }

    while(count5>0){
        ans = (ans * 5)%10;
        count5--;
    }

    if(ans==0) cout<<-1;
    else cout<<ans;

    return 0;
}