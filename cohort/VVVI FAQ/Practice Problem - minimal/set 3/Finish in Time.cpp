#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    vector<pair<int, int>> arr;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        arr.push_back({b, a});
    }
    sort(arr.begin(), arr.end());
    int ans=1;
    int last = arr[0].first;
    for(int i=1; i<n; i++){
        if(arr[i].second > last){
            ans++;
            last = arr[i].first;
        }
    }
    cout<<ans;

    return 0;
}