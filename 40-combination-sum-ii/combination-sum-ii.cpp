class Solution {
public:
    // void helper(vector<int>&candidates, int n, int target, int ind,
    // vector<int>&ds, set<vector<int>>&ans){

    //     if(ind == n){
    //         if(target == 0){
    //             ans.insert(ds);
    //             return;
    //         }
    //         else return;
    //     }
    //     if(target>=candidates[ind]){
    //         ds.push_back(candidates[ind]);
    //         helper(candidates, n, target-candidates[ind], ind+1, ds, ans);
    //         ds.pop_back();

    //     }

    //     helper(candidates, n, target, ind+1, ds, ans);
    // }
    // vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    // {
    //     int n = candidates.size();
    //     sort(candidates.begin(), candidates.end());
    //     vector<int>ds;
    //     set<vector<int>>ans;

    //      helper(candidates, n, target, 0, ds, ans);
    //     vector<vector<int>>result(ans.begin(), ans.end());
    //     return result;

    // time complexity = 2^n*k

    void helper(vector<int>& candidates, int n, int target, int ind,
                vector<int>& ds, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        for (int i = ind; i < candidates.size(); i++) {
            if (i > ind && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (candidates[i] > target)
                break;

            ds.push_back(candidates[i]);
            helper(candidates, n, target - candidates[i], i + 1, ds, ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());

        vector<int> ds;
        vector<vector<int>>ans;

        helper(candidates, n, target, 0, ds, ans);

        return ans;
    }
};