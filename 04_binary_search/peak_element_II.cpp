// TC - O( rows * log column)
class Solution {
public:
    int maxelerow(vector<vector<int>>& mat, int mid, int rows) {
        int maxele = -1;
        int index = -1;
        for (int i = 0; i < rows; i++) {
            if (mat[i][mid] > maxele) {
                maxele = mat[i][mid];
                index = i;
            }
        } return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int low = 0;
        int high = cols - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int rowind = maxelerow(mat, mid, rows);
            int left = mid -1 >=0 ? mat[rowind][mid-1] : -1;
            int right = mid+1 <cols ? mat[rowind][mid+1] : -1;
            if (mat[rowind][mid] > left && mat[rowind][mid] > right) return{rowind,mid};
            else if( mat[rowind][mid] < right) low = mid+1;
            else high = mid -1;
        }
        return {-1,-1};
    }
};
