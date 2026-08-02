#include <bits/stdc++.h>
using namespace std;

string str;
int ans=0, start;

bool solve(int i, int j){
    while(i>=0 && j<str.size()){
        if(str[i]==str[j]){
            if(ans < j-i+1){
                ans = j-i+1;
                start = i;
            }
            i--; j++;
        }
        else break;
    }
}

int main() {
    int t; cin>>t;
    while(t--){
        cin>>str;
        ans=0;
        for(int i=0; i<str.size(); i++){
            solve(i, i);
            solve(i, i+1);
        }
        cout<<str.substr(start, ans)<<"\n";
    }
    
    return 0;
}