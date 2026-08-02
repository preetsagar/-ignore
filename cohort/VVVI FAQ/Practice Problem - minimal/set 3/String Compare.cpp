
#include <bits/stdc++.h>
using namespace std;


bool StringCompare(string s, string t) {
	// string s_out = "";
    // for(int i=0; i<s.size(); i++){
    //     if(s[i]!='#') s_out.push_back(s[i]);
    //     else{
    //         if(!s_out.empty()) s_out.pop_back();
    //     }
    // }
    // string t_out = "";
    // for(int i=0; i<t.size(); i++){
    //     if(t[i]!='#') t_out.push_back(t[i]);
    //     else{
    //         if(!t_out.empty()) t_out.pop_back();
    //     }
    // }

    // return s_out==t_out;

    int i=s.size()-1;
    int j=t.size()-1;

    while(i>=0 || j>=0){
        int backSpace=0;
        while(i>=0){
            if(s[i]=='#'){
                backSpace++;
                i--;
            }else if(backSpace){
                backSpace--;
                i--;
            }else break;
        }
        backSpace=0;
        while(j>=0){
            if(t[j]=='#'){
                backSpace++;
                j--;
            }else if(backSpace){
                backSpace--;
                j--;
            }else break;
        }

        if(i >= 0 && j >= 0){
            if(s[i] != t[j]) return false;
        }
        else if(i >= 0 || j >= 0){
            return false;
        }

        i--;
        j--;
    }
    return true;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s, t;
	cin >> s >> t;
	if (StringCompare(s, t))
		cout << "Yes";
	else
		cout << "No";
}
