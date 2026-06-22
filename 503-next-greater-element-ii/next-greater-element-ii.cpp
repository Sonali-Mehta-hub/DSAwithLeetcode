class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // int n = nums.size();
        // vector<int>ans(n,-1);

        // for(int i=0;i<n;i++){
        //     for(int j=(i+1)%n;j!=i;j=(j+1)%n){
        //         if(nums[i]<nums[j]){
        //             ans[i]=nums[j];
        //             break;
        //         }

        //     }
        // }

        // return ans;

        int n = nums.size();
        stack<int>st;
        vector<int>nge(n);

        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i%n]){
                st.pop();
            }
            if(i<n){
                nge[i]=st.empty()?-1:st.top();
            }
            st.push(nums[i%n]);
        }
        return nge;
    }
};