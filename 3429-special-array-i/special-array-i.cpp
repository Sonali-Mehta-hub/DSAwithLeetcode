class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        int i=1;
        if(n<2)return true;
        while(i<n){
            if((nums[i-1]%2==0 && nums[i]%2==0) || (nums[i-1]%2==1 && nums[i]%2==1)){
                return false;
            }
            i++;
        }

        return true;
    }
};