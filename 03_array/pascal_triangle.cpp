// for printing entire triangle
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            ans.push_back(vector<int>(i + 1, 1));
            for (int j = 1; j < i; j++) {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
        return ans;
    }
};

// for a particular row
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long ans = 1;
        vector<int>matrix(1,1);
        for(int i = 1 ; i<= rowIndex ; i++){
            ans = ans *(rowIndex + 1 - i) / i ;
            matrix.push_back(ans); 
        }
        return matrix;
    }
};
