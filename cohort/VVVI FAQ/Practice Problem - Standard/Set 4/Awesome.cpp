#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--){
        string s; cin>>s;
        int n=s.size();
        int mask=0;
        unordered_map<int, int> m;
        int ans=0;
        m[0] = -1;

        for(int i=0; i<n; i++){
            mask ^= (1<<(s[i]-'0'));
            
            if(m.find(mask)!=m.end()){
                ans = max(ans, i-m[mask]);
            }
            for(int j=0; j<10; j++){
                if(m.find(mask^(1<<j))!=m.end()){
                    ans = max(ans, i-m[mask^(1<<j)]);
                }
            }

            if(m.find(mask)==m.end()) m[mask] = i;
        }
        cout<<ans<<"\n";
        
    }
    return 0;
}