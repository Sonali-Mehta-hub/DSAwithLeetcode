class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n= nums.size();
        int num_xor=0;
        for(int i=0;i<n;i++){
           num_xor^=nums[i];
        }

        return num_xor;
    }
};