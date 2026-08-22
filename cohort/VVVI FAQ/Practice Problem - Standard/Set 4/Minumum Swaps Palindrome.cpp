#include <bits/stdc++.h>
using namespace std;

string s;
map<char, int> m;

int main() {
    int t; cin>>t; while(t--){
        cin>>s;
        m.clear();
        for(char i:s) m[i]++;
        int singleChar=0;
        for(auto i:m){
            if(i.second%2==1) singleChar++;
        }
        if(singleChar>1) {cout<<-1<<'\n'; continue;}

        int ans=0;
        int l=0,r=s.size()-1;
        while(l<r){
            if(s[l]==s[r]){
                l++; r--;
            }else{
                int j=r;
                while(j>=l && s[l]!=s[j]) j--;

                int i=l;
                while(i<=r && s[i]!=s[r]) i++;
                // cout<<"l="<<l<<" i="<<i<<" j="<<j<<" r="<<r;

                // fix l
                if(r-j < i-l){
                    for(int k=j; k<r; k++) swap(s[k], s[k+1]);
                    ans += r-j;
                }else{ // fix r
                    for(int k=i; k>l; k--) swap(s[k], s[k-1]);
                    ans += i-l;
                }
                // cout<<"   "<<s<<"\n";
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}