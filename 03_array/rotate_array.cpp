// brute force: create new array TC - O(n^2)... SC - O(n^2)
class Solution {
public:
    vector < vector < int >> rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
         vector < vector < int >> ans(n,vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][n-1-i]=matrix[i][j];
            }
        }
        return ans;
        
    }
};
//OPTIMAL SOLUTION - TRANSPONSE THE MATRIX AND THEN REVERSE THE ROWS.....
//TRANSPOSE IS DONE BY SWAPPING ELEMENTS IN EITHER UPPER OR LOWER HALF OF DIAGONAL WITH THE OTHER HALF
class Solution{
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i+1; j < matrix.size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
