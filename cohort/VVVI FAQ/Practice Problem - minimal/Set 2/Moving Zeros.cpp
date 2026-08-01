
#include <bits/stdc++.h>
using namespace std;


void MovingZeros(vector <int>& nums) {
    int l=0;
    int i=0;
    while(i<nums.size()){
        if(nums[i]){
            swap(nums[i], nums[l]);
            l++;
        }
        i++;
    }
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector <int> nums(n);
	for (auto &i : nums)
		cin >> i;
	MovingZeros(nums);
	for (auto i : nums)
		cout << i << " ";
}
