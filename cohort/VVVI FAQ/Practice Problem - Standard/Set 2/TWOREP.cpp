
#include <bits/stdc++.h>
using namespace std;


vector<int> FindRepeated(vector<int> &a)
{
    int xxor=0;
    for(int i:a) xxor ^= i;
    int idx;
    for(int i=0; i<32; i++){
        if(xxor&(1<<i)){
            idx=i;break;
        }
    }

    int x=0,y=0;
    for(int i:a){
        if((1<<idx)&i){
            x ^= i;
        }else{
            y ^= i;
        }
    }
    return {min(x,y),max(x,y)};
}


int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(2 * n + 2);

    for (int i = 0; i < 2 * n + 2; i++)
        cin >> a[i];

    vector<int> ans = FindRepeated(a);
    cout << ans[0] << " " << ans[1] << "\n";
}
