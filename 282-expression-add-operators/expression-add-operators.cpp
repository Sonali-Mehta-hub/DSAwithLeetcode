class Solution {
public:
    void helper(string num,int target, int n,string expression,int ind,long last_op,long current_val,vector<string>&ans){
       
       if(ind==n){
        if(target==current_val){
            ans.push_back(expression);
            
        }
        return;
       }
       long current_number = 0;

       for(int i=ind;i<n;i++){
          if(i>ind && num[ind]=='0')break;

          current_number = current_number*10+(num[i]-'0');
          string current_string = num.substr(ind, i-ind+1);

          if(ind==0){
            helper(num,target,n,current_string,i+1,current_number,current_number, ans);
          }
          else{
              helper(num,target,n,
                     expression+"+"+current_string,
                     i+1,
                     current_number,
                     current_val+current_number,
                     ans);

              helper(num,target,n,
                     expression+"-"+current_string,
                     i+1,
                     -current_number,
                     current_val-current_number,
                     ans);

              helper(num,target,n,
                     expression+"*"+current_string,
                     i+1,
                     last_op*current_number,
                     current_val-last_op+(last_op*current_number),
                     ans);

          }
       }
    }
    vector<string> addOperators(string num, int target) {
        int n= num.size();
        string expression="";
        vector<string>ans;

        helper(num,target,n,expression, 0,0,0,ans);
        return ans;
    }
};