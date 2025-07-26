//TLE for very large values of n
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        double y = x;
        if (N == 0)
            return 1;
        if(x==1) return 1;
        int sign = 1;
        if (N < 0) {
            sign = -1;
           N = -1 *N;
        }
        while (N > 1) {
            x = x * y;
            N--;
        }
        if (sign == -1)
            return (1 / x);
        return x;
    }
};
// EXPONENTIAL SOLN - IF POWER IS FACTOR OF 2 THEN SQUARE YOUR X; O(log n)
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(x == 1) return 1;
        long long N = n;
        double ans = 1;
        if(N<0) N = -1* N;
        while(N>0){
            if(N%2 == 0) {
                x = x*x;
                N = N/2;
            }
            else{
                ans =ans* x;
                N = N-1;
            }
        }
        if(n<0) return (double)1 / (double)ans;
        return ans;
        
    }
};
