class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanval = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
            int val = 0;
            for(int i = 0 ; i<s.size() ; i++){
                
                if(i+1<s.size() && romanval[s[i]] < romanval[s[i+1]]) val-=romanval[s[i]];
                else val+= romanval[s[i]];
            }
            return val;
    }
};
// TC - O(N) AND SC -O(1)
