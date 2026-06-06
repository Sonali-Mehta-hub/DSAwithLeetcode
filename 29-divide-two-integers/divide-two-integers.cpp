class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == divisor) return 1;

        bool sign = !((dividend < 0) ^ (divisor < 0));

        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);

        long long ans = 0;

        while (n >= d) {

            int count = 0;

            while (n >= (d << (count + 1))) {
                count++;
            }

            ans += (1LL << count);
            n -= d * (1LL << count);
        }

        if (ans >= (1LL << 31)) {
            return sign ? INT_MAX : INT_MIN;
        }

        return sign ? (int)ans : (int)(-ans);
    }
};