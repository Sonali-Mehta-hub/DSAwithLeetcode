// class Solution {
// public:
    // const long long MOD = 1000000007;

    // long long power(long long base, long long exp) {
    //     long long result = 1;
    //     while (exp > 0) {
    //         if (exp % 2 == 1) {
    //             result = (result * base) % MOD;
    //         }
    //         base = (base * base) % MOD;
    //         exp /= 2;
    //     }
    //     return result;
    // }

    // int countGoodNumbers(long long n) {
    //     long long evenPos = (n + 1) / 2;  // even indices count
    //     long long oddPos = n / 2;         // odd indices count
        
    //     long long evenPart = power(5, evenPos);
    //     long long oddPart = power(4, oddPos);
        
    //     return (evenPart * oddPart) % MOD;

//     }
// };


    //recursion part...........................

class Solution {
public:
    const long long MOD = 1000000007;

    long long power(long long base, long long exp) {
        if (exp == 0) return 1;

        long long half = power(base, exp / 2);
        long long result = (half * half) % MOD;

        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2;
        long long oddPos = n / 2;

        long long evenPart = power(5, evenPos);
        long long oddPart = power(4, oddPos);

        return (evenPart * oddPart) % MOD;
    }
};
    