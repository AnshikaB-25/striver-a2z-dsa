class Solution {
public:
    int beautySum(string s) {
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            vector<int> hash(26);
            hash[s[i] - 'a']++;
            for (int j = i + 1; j < s.size(); j++) {
                hash[s[j] - 'a']++;
                int maxele = INT_MIN;
                int minele = INT_MAX;
                for (int k = 0; k < 26; k++) {
                    if (hash[k] > 0) {
                        maxele = max(hash[k], maxele);
                        minele = min(hash[k], minele);
                    }
                }
                if (maxele != minele) {
                    count += maxele - minele;
                }
            }
        }
        return count;
    }
};
//For every substring, instead of comparing just two characters, you should check the frequency of all 26 lowercase letters. This ensures you correctly identify the actual most and least frequent characters.
//Initialize maxele as INT_MIN and minele as INT_MAX for each new substring. This ensures clean and correct calculation for every case.
