class Solution {
public:
//palindrome partitioning
    bool isPallindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
            
        }
        return true;
    }
    void findPart(string s, int n, vector<string>&subpart, vector<vector<string>>&ans, int ind){
        if(ind==n){
            ans.push_back(subpart);
            return;
        }
        for(int i=ind;i<n;i++){
            if(isPallindrome(s,ind, i)){
                subpart.push_back(s.substr(ind,i-ind+1));
                findPart(s,n,subpart, ans,i+1);
                subpart.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string>subpart;
        vector<vector<string>>ans;
        findPart(s,n,subpart,ans, 0);
        return ans;
    }
};