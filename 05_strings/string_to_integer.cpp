//overflow occurs in val * 10 before you even check it — resulting in undefined behavior.

The solution checks if val * 10 + digit would exceed LLONG_MAX before doing the operation — keeping it safe.
class Solution {
public:
    int myAtoi(string s) {
        long long val = 0;
        int sign = 1;
        int n = s.size();
        int first = 0;
        while (first < n && s[first] == ' ')
            first++;   
        if(first<n && (s[first]=='-' || s[first] =='+' )){
            if (s[first]=='-') sign = -1;
            first++;
        }
        while (first < n && isdigit(s[first])){
            int digit = s[first] - '0';
            if (val > (LLONG_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            val = (val * 10) + (digit);
            first++;
        }
        if(val*sign >= INT_MAX) return INT_MAX;
        if(val*sign <= INT_MIN) return INT_MIN;
        return val*sign;
    }
};
