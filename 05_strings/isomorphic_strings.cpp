class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        int m = t.length();
        if (n != m) return false;
        for(int i = 0 ; i<n ; i++){
            char ele1 = s[i];
            for(int j = i+1; j<n ; j++){
                char ele2 = s[j];
                if(ele2 == ele1){
                    if(t[j]!= t[i]) return false;
                }
                else{
                    if(t[j]==  t[i])return false;
                }
            }
        }
        return true;
    }
}; 
// optimal...
// Mistake: Initially set hash arrays to 0, causing confusion between unseen characters and those seen at index 0.
//✅ Fix: Initialized with -1 to clearly distinguish unseen characters, ensuring correct index comparison for isomorphic mapping.
//The line hash[s[i]] = i seemed odd, but it's updating the last seen index of the character — ensuring that the mapping is consistent across positions.
//✅ Key Idea: If two characters map to the same index pattern in both strings, they’re isomorphic. The = i stores that pattern accurately.
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        int m = t.length();
        if (n != m) return false;
        vector<int>hash(256,-1);
        vector<int>hash1(256,-1);
        for(int i = 0 ; i<n ; i++){
           if(hash[s[i]]!= hash1[t[i]]) return false;
           hash[s[i]]=i;
           hash1[t[i]]=i;
        }
        return true;
        
    }
};
