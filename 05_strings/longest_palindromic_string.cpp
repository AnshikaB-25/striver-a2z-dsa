class Solution {
public:
    int maxfreq(string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
    string longestPalindrome(string s) {
        int maxf = 0;
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            int len1 = maxfreq(s, i, i);
            int len2 = maxfreq(s, i, i + 1);
            int currentmax = max(len1, len2);
            if (currentmax > maxf) {
                maxf = max(currentmax, maxf);
                start = i - (currentmax - 1) / 2;
            }
        }
        return s.substr(start, maxf);
    }
};
