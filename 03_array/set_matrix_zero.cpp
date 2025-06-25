// BRUTE FORCE: TC IS O(n^3)
class Solution {
public:
    void mark_rows(vector<vector<int>>& matrix, int i) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0)
                matrix[i][j] = -1;
        }
    }
    void mark_columns(vector<vector<int>>& matrix, int j) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            if (matrix[i][j] != 0)
                matrix[i][j] = -1;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    mark_rows(matrix, i);
                    mark_columns(matrix, j);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1) {
                   matrix[i][j]=0;
                }
            }
        }
    }
};

// BETTER SOLN : AVOID THE THIRD LOOP AND USE EXTRA SPACE.... TC - O(2*n*m)
// SC - O(N+m)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rows(m,0);
        vector<int> cols(n,0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(matrix[i][j]==0){
                    cols[j]=1;
                    rows[i]=1;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(rows[i]==1 || cols[j]==1){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

// OPTIMAL SOLN
