class Solution {
public:
    void helper(string num, int target,int n,vector<string>&ans,int ind, long current_value,string expression,long last_op){

        if(ind==n){
            if(current_value==target){
                ans.push_back(expression);
            }
            return;
        }

        long current_number = 0;
        string current_string="";

        for(int i=ind;i<n;i++){
            if(i>ind && num[ind]=='0')break;
            
            current_number = current_number*10+(num[i]-'0');
            current_string = num.substr(ind,i-ind+1);

            if(ind==0){
                helper(num,target,n,ans,
                        i+1,
                        current_number,
                        current_string,
                        current_number);
            }
            else{
                //addition
                helper(num,target,n,ans,
                       i+1,
                       current_number+current_value,
                       expression+"+"+current_string,
                       current_number);

                //subtraction
                helper(num,target,n,ans,
                       i+1,
                       current_value-current_number,
                       expression+"-"+current_string,
                       -current_number);

                //multiplication
                helper(num,target,n,ans,
                       i+1,
                       current_value-last_op+(last_op*current_number),
                       expression+"*"+current_string,
                       current_number*last_op);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        int n = num.size();
        string expression ="";
        vector<string>ans;

        helper(num,target,n,ans,0,0,expression,0);
        return ans;
    }
};