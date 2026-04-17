class Solution {
public:
    int myAtoi(string s) {
        int n= s.size();
        int i=0;
        int j = n-1;

        //remove whitespace
        while(i<=j && s[i]==' ')i++;
        while(i<=j && s[j]==' ')j--;

        int sign ;
        //handle sign
        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(s[i]=='+'){
            sign=+1;
            i++;
        }
        else{
            sign=+1;
        }

        int result = 0;

        while(i<=j && isdigit(s[i])){
            int digit = s[i]-'0';

            if(result>INT_MAX/10 ||(result==INT_MAX/10 && digit>7)){
                if(sign==+1)return INT_MAX ;
                else return INT_MIN;
            }
            result = result*10+digit;
            i++;
        }

        if(result){
            return sign*result;
        }
        else return result;

    }
};