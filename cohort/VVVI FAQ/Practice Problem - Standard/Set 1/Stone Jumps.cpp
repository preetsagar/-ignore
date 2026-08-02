
#include <bits/stdc++.h>
using namespace std;


bool isReach(vector<int> jump)
{
    int n=jump.size();
	int maxReach = 0;
    for(int i=0; i<n; i++){
        if(i<=maxReach){
            maxReach = max(maxReach, i+jump[i]);
        }
    }
    return maxReach >= n-1;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector<int> jump(n);
	for (auto &i : jump)
		cin >> i;

	if (isReach(jump))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
