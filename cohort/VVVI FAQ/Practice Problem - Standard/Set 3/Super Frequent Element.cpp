
#include <bits/stdc++.h>
using namespace std;


int SuperFrequentElement(vector<int> &v)
{
    int candidate,vote=0;
    for(int c:v){
        if(vote==0){
            candidate = c;
            vote=1;
        }else if(candidate==c){
            vote++;
        }else{
            vote--;
        }
    }

    return candidate;
}


int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;

    cout << SuperFrequentElement(v) << "\n";
}
