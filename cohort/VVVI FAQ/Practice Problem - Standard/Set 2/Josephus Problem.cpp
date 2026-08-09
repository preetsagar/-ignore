#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<int> arr;

int solve(int i){
    if(arr.size()==1) return arr[0];

    int s=arr.size();
    int kill = (i+k)%s;
    arr.erase(arr.begin()+kill);
    return solve(kill);
}

int main() {
    cin>>n>>k;
    for(int i=1; i<=n; i++) arr.push_back(i);

    k--;
    cout<<solve(0);

    return 0;
}