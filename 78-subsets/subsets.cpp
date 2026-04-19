class Solution {
public:
    void powSet(int index, int n, vector<int>& nums, vector<int>& ds, vector<vector<int>>&ans){
        if(index==n){
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[index]);
        powSet(index+1,n, nums ,ds, ans);

        ds.pop_back();
        powSet(index+1,n,nums,ds,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
    //recursive concept........
    int n=nums.size();
    vector<vector<int>>ans;
    vector<int>ds;

    powSet(0,n,nums,ds,ans);
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