class Solution {
public:
    void helper(vector<int>&candidates, int n, int target, int ind, vector<int>&ds, vector<vector<int>>&ans){
        
        if(ind ==n){
            if(target==0){
                ans.push_back(ds);
                return ;
            }
            else {
                return;
            }
        }
        if(candidates[ind]<=target){
            ds.push_back(candidates[ind]);
            helper(candidates, n, target-candidates[ind], ind, ds, ans);
            ds.pop_back();
        }
        
            helper(candidates, n , target, ind+1, ds, ans);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

       int n = candidates.size();
       vector<int> ds;
       vector<vector<int>>ans;

       helper(candidates, n ,target, 0, ds, ans);

       return ans;
        
    }
};