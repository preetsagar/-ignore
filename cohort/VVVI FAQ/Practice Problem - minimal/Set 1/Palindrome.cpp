#include <bits/stdc++.h>
using namespace std;

string s;

bool isPalindrome(string &s, int l, int r){
    while(l < r){
        if(s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

bool solve(string &s){
    int l = 0, r = s.size() - 1;

    while(l < r){
        if(s[l] == s[r]){
            l++;
            r--;
        }else{
            return isPalindrome(s, l+1, r) ||
                   isPalindrome(s, l, r-1);
        }
    }

    return true;
}

int main() {
    int t; cin>>t; while(t--){
        cin>>s;
        int ans = solve(s);
        if(ans) cout<<"Y\n";
        else cout<<"N\n";
    }
    return 0;
}