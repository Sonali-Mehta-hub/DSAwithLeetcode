class Solution {
public:
    bool helper(string s,int n, int start, unordered_set<string>&st, vector<int>&dp){
        if(start==n)return true;
        if(dp[start]!=-1)return dp[start];

        for(int end = start;end<n;end++){
            if(st.find(s.substr(start, end-start+1))!=st.end()){
                if(helper(s,n,end+1,st,dp)){
                    return dp[start]=true;
                }
            }
        }
        return dp[start]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        vector<int>dp(n,-1);
         return helper(s,n,0,st,dp);
    }
};