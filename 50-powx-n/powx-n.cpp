class Solution {
public:
//     Because int is not symmetric. Its range is:
//     -2^31 to 2^31 - 1
// →   -2147483648 to 2147483647

    double calPow(double X, int N){
        if(N==0)return 1;
        double half = calPow(X,N/2);
        if(N%2==0){
            return half*half;
        }
        else{
            return half*half*X;
        }

    }
    double myPow(double x, int n) {
        double X=x; long long N=n;
        if(N<0){
            X=1/X;
            N=-N;
        }

         return calPow(X,N);
    }
};