
#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<int> arr;

void NearlySort(){
	cin>>n>>k;
    for(int i=0; i<n; i++){
        int t; cin>>t; arr.push_back(t);
    }

    priority_queue<int> pq;
    for(int i=0; i<n; i++){
        pq.push(-arr[i]);
        if(i>=k){
            arr[i-k] = -pq.top(); pq.pop();
        }
    }
    
    for(int i=n-k; i<n; i++){
        arr[i] = -pq.top(); pq.pop();
    }

    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	NearlySort();
	return 0;
}
