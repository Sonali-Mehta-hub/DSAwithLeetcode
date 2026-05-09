class Solution {
public:
    void findSubset(vector<int>&nums, int n, vector<int>ds,int ind, vector<vector<int>>&ans){
        ans.push_back(ds);
        for(int i=ind;i<n;i++){
            if(i!=ind && nums[i]==nums[i-1])continue;
            ds.push_back(nums[i]);
            findSubset(nums, n, ds, i+1,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(), nums.end());
        findSubset(nums, n, ds, 0,ans);
        return ans;
        
    }
};