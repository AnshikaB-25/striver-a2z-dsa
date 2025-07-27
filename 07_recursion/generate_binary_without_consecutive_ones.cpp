//O(2^n)
class Solution {
   public:
    void generate(int n, string current, vector<string>&result, char prev) {
        if(current.length()==n){
            result.push_back(current);
            return;
        }
        generate(n,current+'0' , result , '0');
        if(prev!= '1') generate(n,current+'1',result, '1');
    }
    vector<string> generateBinaryStrings(int n) {
        vector<string> result;
        generate(n, "", result, '0');
        return result;
    }
};
