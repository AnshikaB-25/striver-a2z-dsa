// identify the number of odd and even indices and how many values are permitted in it
class Solution {
public:
    const int mod = 1e9 + 7;
    long long myPow(long long x, long long n) {
        x %=mod;
        if (x == 1)
            return 1;
        long long N = n;
        long long ans = 1;
        while (N > 0) {
            if (N % 2 == 0) {
                x = (x * x) % mod;
                N = N / 2;
            } else {
                ans = (ans * x) % mod;
                N = N - 1;
            }
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long odd1 = 1;
        long long even1 = 1;
        odd1 = (long long)myPow(4, n / 2);
        even1 = (long long)myPow(5, (n + 1) / 2);
        return ( odd1 * even1) % mod;
    }
};
