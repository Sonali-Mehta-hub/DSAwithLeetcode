class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n = nums1.size();
        int m = nums2.size();
        vector<int>nge(m);

        for(int i=m-1;i>=0;i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }

            if(st.empty()){
                nge[i]=-1;
            }
            else{
                nge[i]=st.top();
            }
            st.push(nums2[i]);
        }

        unordered_map<int,int>mp;

        for(int i=0;i<m;i++){
            mp[nums2[i]]=nge[i];
        }

        vector<int>ans;

        for(int i=0;i<n;i++){
            ans.push_back(mp[nums1[i]]);
        }

       return ans; 
    }
};