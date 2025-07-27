class Solution {
public:
void generate(int n , string current , vector<string>&result , int countf , int countb){
    if(n==countf && n == countb){
        result.push_back(current);
        return;
    }
    if(n!=countf) generate(n,current+'(',result, countf+1, countb);
    if(countf>countb)generate(n,current+')',result,countf,countb+1);
}
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        generate(n,"(",result,1,0);
        return result;
    }
};
