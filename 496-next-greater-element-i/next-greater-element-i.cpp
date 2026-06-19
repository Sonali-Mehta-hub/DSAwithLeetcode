class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m = nums2.size();

        vector<int>ans;

        for(int i=0;i<n;i++){
            int idx=0;
            for(int j=0;j<m;j++){
                if(nums1[i]==nums2[j]){
                    idx=j;
                    break;
                }
            }
            int nge =-1;

            for(int k=idx+1;k<m;k++){
               if(nums2[idx]<nums2[k]){
                nge=nums2[k];
                break;
               }
            }
            ans.push_back(nge);
        }
        return ans;
    }
};