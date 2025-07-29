
class Solution {
public:
bool ispalindrome(string s , int first , int last){
    if(s.size()==1) return true;
    while(first<last){
        if(s[first++] != s[last--]) return false;
    } 
    return true;
}
    void findpalindrome(vector<vector<string>>&ans, vector<string>&output, string s, int index){
        if(index == s.size()){
            ans.push_back(output);
            return;
        }
        for(int i = index ; i<s.size(); i++){
            if(ispalindrome(s,index,i)){
                output.push_back(s.substr(index, i -index+1));
                findpalindrome(ans,output,s,i+1);
                output.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>output;
        int index = 0;
        findpalindrome(ans,output,s,0);
        return ans;
    }
};
