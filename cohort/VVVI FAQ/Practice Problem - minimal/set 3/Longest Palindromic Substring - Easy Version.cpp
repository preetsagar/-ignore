#include <bits/stdc++.h>
using namespace std;

string str;

bool solve(int i, int j){
    if(i>=j) return true;

    if(str[i]==str[j]){
        return solve(i+1, j-1);
    }
    else return false;

}

int main() {
    int t; cin>>t;
    while(t--){
        cin>>str;
        int ans=0, ans_i;
        for(int i=0; i<str.size(); i++){
            for(int j=0; j<str.size(); j++){
                if(solve(i, j)){
                    if(j-i+1 > ans){
                        ans = j-i+1;
                        ans_i = i;
                    }
                }
            }
        }
        cout<<str.substr(ans_i, ans)<<"\n";
    }
    
    return 0;
}