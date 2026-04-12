class Solution {
public:
    void helper(int ind,vector<int> &ds, vector<int>&nums, int n, vector<vector<int>>&ans){
        if(ind>=n){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        helper(ind+1, ds, nums, n, ans);

        ds.pop_back();
        helper(ind+1, ds,nums, n, ans);
    
    }
    vector<vector<int>> subsets(vector<int>& nums) {
    //recursive concept........
    int n= nums.size();
    vector<vector<int>>ans;
    vector<int>ds;
    helper(0,ds, nums,n,ans);
     
     return ans;

        //bit manupulation concept.....................
    //    vector<vector<int>>ans;
    //    int n = nums.size();
    //    int iter = 1<<n; //2^n subsets

    //    for(int i=0;i<iter;i++){
    //     vector<int>subset;
    //     for(int j=0;j<n;j++){
    //         if(i & (1<<j)){
    //             subset.push_back(nums[j]);
    //         }
    //     }
    //     ans.push_back(subset);
    //    }

    //    return ans;
    }
};