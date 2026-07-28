class Solution {
public:
    vector<vector<int>> ans;
    vector<int> ds;

    void solve(vector<int>& candidates, int i, int target){
        if(target<0) return;
        if(i == candidates.size()){
            if(target==0) ans.push_back(ds);
            return;
        }

        // take
        ds.push_back(candidates[i]);
        solve(candidates, i+1, target-candidates[i]);
        ds.pop_back();

        // not take
        int j=i+1;
        while(j<candidates.size() && candidates[j]==candidates[i]) j++;
        solve(candidates, j, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, target);
        return ans;
    }
};