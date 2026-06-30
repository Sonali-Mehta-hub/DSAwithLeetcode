class Solution {
public:
    vector<int>findNse(vector<int>&nums){
        int n = nums.size();
        vector<int>nse(n);
        stack<int>st;

        for(int i = n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }

            nse[i] = st.empty()?n:st.top();

            st.push(i);
        }

        return nse;
    }

    vector<int>findPsee(vector<int>&nums){
        int n = nums.size();
        vector<int>psee(n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }

            psee[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        return psee;
    }
    long long sumMin(vector<int>&nums){
        int n = nums.size();
        vector<int>nse = findNse(nums);
        vector<int>psee = findPsee(nums);
        long long total = 0;

        for(int i=0;i<n;i++){
            long long left = i-psee[i];
            long long right = nse[i]-i;
            
            total+=left*right*nums[i];

        }

        return total;
    }
    vector<int>findPgee(vector<int>&nums){
        int n = nums.size();
        vector<int>pgee(n);
        stack<int>st;

        for(int i = 0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();

            }
            pgee[i] = st.empty()?-1:st.top();

            st.push(i);
        }
        return pgee;
    }
    vector<int>findNge(vector<int>&nums){
        int n = nums.size();
        vector<int>nge(n);
        stack<int>st;

        for(int i = n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();

            }
            nge[i] = st.empty()?n:st.top();

            st.push(i);
        }
        return nge;
    }
    long long sumMax(vector<int>&nums){
        int n = nums.size();
        vector<int>nge = findNge(nums);
        vector<int>pgee = findPgee(nums);
        long long total = 0;

        for(int i=0;i<n;i++){
            long long left = i-pgee[i];
            long long right = nge[i]-i;

            total+=left*right*nums[i];
        }

        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumMax(nums)-sumMin(nums);
    }
};