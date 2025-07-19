//tc - o(n log n + m)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string ele1 = strs[0];
        string ele2 = strs[strs.size() - 1];
        int i = 0;
        string ans = "";
        while (i < min(ele1.length(), ele2.length())) {
            if (ele1[i] == ele2[i]) {
                ans.push_back(ele1[i]);
                i++;
            } else
                break;
        }
        return ans;
    }
};
