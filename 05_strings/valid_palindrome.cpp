bool ispalindrome(string s){
    int first = 0; int last = s.size()-1;
    while(first<last){
        if(s[first++] != s[last--]) return false;
    } 
    return true;
}

// valid PALINDROME.... TC - O(N)....SC - O(N)
class Solution {
public:
    bool isPalindrome(string s) {
        string result ="";
        for (char c:s){
            if (isalnum(c)) result+=tolower(c);
        }
        int first = 0; int last = result.size()-1;
        while(first<last){
            if(result[first++]!= result[last--]) return false;
        } 
        return true; 
        
    }
};
// OPTIMAL USING TWO POINTERS
class Solution {
public:
    bool isPalindrome(string s) {
        int first = 0;
        int last = s.size() - 1;
        while (first < last) {
            while (first < last && !isalnum(s[first]))
                first++;
            while (first < last && !isalnum(s[last]))
                last--;
            if (tolower(s[first]) != tolower(s[last]))
                return false;

            first++;
            last--;
        }
        return true;
    }
};
