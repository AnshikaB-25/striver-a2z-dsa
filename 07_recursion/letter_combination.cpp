//TC - O(4^N) as for each digit there can be upto four letters so four cases
class Solution {
public:
    void findcombo(vector<string>& ans, string digits, map<char, string>& mpp,
                   string s, int index) {
        if (index == digits.length()) {
            ans.push_back(s);
            return;
        }
        for(char c :mpp[digits[index]]){
            s.push_back(c);
            findcombo(ans,digits,mpp,s,index+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        map<char, string> mpp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                 {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                 {'8', "tuv"}, {'9', "wxyz"}};
        int index = 0;
        string s = "";
        findcombo(ans, digits, mpp, s, 0);
        return ans;
    }
};
