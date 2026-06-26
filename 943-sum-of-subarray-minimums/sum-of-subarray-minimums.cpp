class Solution {
public:
    vector<int>find_Nse(vector<int>&arr){
        vector<int>nse(arr.size());
        stack<int>st;

        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }

            nse[i]= st.empty()?arr.size():st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int>find_Psee(vector<int>&arr){
        vector<int>psee(arr.size());
        stack<int>st;

        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();

            }

            psee[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        return psee;
    }
    int sumSubarrayMins(vector<int>& arr) {
        // int n = arr.size();
        // const int MOD = 1e9 + 7;
        // long long sum = 0;

        // for(int i = 0; i < n; i++) {
        //     int minNum = arr[i];

        //     for(int j = i; j < n; j++) {
        //         minNum = min(minNum, arr[j]);
        //         sum = (sum + minNum) % MOD;
        //     }
        // }

        // return sum;
        int n=arr.size();
        vector<int>nse = find_Nse(arr);
        vector<int>psee = find_Psee(arr);

        long long total=0;
        const int MOD=1e9+7;

       for(int i=0;i<n;i++){
          long long left = i-psee[i];
          long long right = nse[i]-i;

         total = (total + (left * right % MOD) * arr[i] % MOD) % MOD;

       }
       return total;

    }
};