// my approach
class Solution {
public:
    string reverseWords(string s) {
        int first = 0; int last = s.size()-1;
        while (s[first] == ' ') first++;
        while (s[last]== ' ') last--; 
        string ans = "";
        string temp = "";
        for(int j= last ; j>=first ; j--){
            if(s[j] != ' ') {
                temp.push_back(s[j]);
            }
            else if(!temp.empty()){
                reverse(temp.begin(), temp.end());
                ans +=temp + " ";
                temp = "";
            }
        }
        if(!temp.empty()) reverse(temp.begin(), temp.end());
        ans+=temp;
        return ans;
        
        
    }
};
// using extra space
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";
        reverse(s.begin(), s.end());
        for (int i = 0; i < n; i++) {
            string temp = "";
            while (i < n && s[i] != ' ') {
                temp += s[i];
                i++;
            }
            reverse(temp.begin(), temp.end());
            if (temp.length()>0) {
                ans += " "+ temp;
            }
        }

        return ans.substr(1);
    }
}; 
// optimal
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n=s.size();
        int left=0;
        int right=0;
        int i=0;
        while(i<n){
            while(i<n && s[i]==' ')i++;
            if(i==n)break; // to stop index going out of bounds
            while(i<n && s[i]!=' '){
                s[right++]=s[i++];
            }
            reverse(s.begin()+left,s.begin()+right);
            s[right++]=' ';
            left=right;
            i++;
        }
        s.resize(right-1);
        return s;
    }
};
