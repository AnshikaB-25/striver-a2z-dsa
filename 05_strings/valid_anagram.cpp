class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if (n != m) return false;
        vector<int>hash(256,-1);
        vector<int>hash1(256,-1);
        for(int i = 0 ; i<n ; i++){
           hash[s[i]]++;
           hash1[t[i]]++;
        }
        for(int i = 0; i<hash.size(); i++){
            if(hash[i] != hash1[i]) return false;
        }
        return true;
    }
};
//Use one hash array (e.g., vector<int> hash(256, 0);) and in a single loop:
//Increment the count for each character in s
//Decrement the count for each character in t
//At the end, if all values in the hash array are 0, the strings are anagrams.
//This improves efficiency by reducing space and loop operations while keeping logic clean
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if (n != m) return false;
        vector<int>hash(256,0);
        for(int i = 0 ; i<n ; i++){
           hash[s[i]]++;
           hash[t[i]]--;
        }
        for(int i = 0; i<hash.size(); i++){
            if(hash[i] != 0) return false;
        }
        return true;
    }
};
