class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;

        for(int i=0;i<n;i++){
            long long maxNum=nums[i];
            long long minNum=nums[i];
            for(int j=i;j<n;j++){
                maxNum = max(maxNum,1LL*nums[j]);
                minNum = min(minNum,1LL*nums[j]);
                sum+=(maxNum-minNum);
            }
        }

        return sum;
    }
};