class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        unordered_map<int,int>pre_sum;
        pre_sum[0]=1;
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem = sum-k;
            if(pre_sum.find(rem)!=pre_sum.end()){
               count+= pre_sum[rem];
            }
            pre_sum[sum]+=1;
     
        }
        return count;
    }
};