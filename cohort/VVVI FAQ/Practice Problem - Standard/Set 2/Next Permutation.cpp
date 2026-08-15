
#include <bits/stdc++.h>
using namespace std;


void solve(vector<int> &v)
{
	int select_idx = -1;
    int n=v.size();
    for(int i=n-1; i>0; i--){
        if(v[i-1]<v[i]){
            select_idx = i-1;
            break;
        }
    }

    int swap_idx;
    if(select_idx!=-1){
        for(int i=n-1; i>select_idx; i--){
            if(v[select_idx]<v[i]){
                swap_idx = i;
                break;
            }
        }
        swap(v[select_idx], v[swap_idx]);
    }
    
    reverse(v.begin()+select_idx+1, v.end());
}


int main() {
	int n;
	cin >> n;
	vector <int> v(n);
	for (auto &i : v)
		cin >> i;

	solve(v);

	for (auto i : v)
		cout << i << " ";
	cout << "\n";
}
