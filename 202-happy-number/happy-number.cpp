class Solution {
public:
    int nextNum(int n){
        int sum =0;

        while(n>0){
            int r = n%10;
            sum+=r*r;
            n = n/10;
        }

        return sum;
    }
    bool reachOne(int n){
        int slow=n;
        int fast=n;

        while(true){
            slow = nextNum(slow);
            fast = nextNum(nextNum(fast));

            if(slow==fast)break;

        }

        return slow==1;
    }
    bool isHappy(int n) {
        return reachOne(n);
    }
};