class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int maxCount = 0;

        for(int i=0;i<n;i++){
            
           if(nums[i]!=1)count = 0;
           else {
            count++;
            maxCount = max(count, maxCount);
           }
        }
        return maxCount ;

    }
};