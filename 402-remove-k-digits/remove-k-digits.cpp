class Solution {
public:
    string removeKdigits(string num, int k) {
       string st;

       for(auto ch : num){
        while(!st.empty() && k>0 && st.back()>ch){
            st.pop_back();
            k--;
        }
        st.push_back(ch);
       }

       while(k>0){
        st.pop_back();
        k--;
       }

      int i=0;
      while(i<num.size() && st[i]=='0'){
        i++;
      }
      string ans = st.substr(i);

      return ans.empty()?"0":ans;
    }
};