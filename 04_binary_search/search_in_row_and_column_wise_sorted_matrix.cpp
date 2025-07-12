// better soln o( n* log m)
class Solution {
public:
    bool binarysearch1(vector<int>&matrix , int target){
        int low = 0; int high = matrix.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(matrix[mid]== target) return true;
            else if(matrix[mid] > target) high = mid-1;
            else low = mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i = 0; i<rows ; i++){
           if (binarysearch1(matrix[i] , target)) return true;
        }
        return false;
    }
};
// optimal o(n+m) search from the 2nd diagonal element
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int rows = matrix.size();
        int cols = matrix[0].size();
        int r1 = 0;
        int c1 = cols-1;
        while(r1 < rows && c1 >=0){
            if(matrix[r1][c1] == target) return true;
            else if(matrix[r1][c1]>target) c1--;
            else r1++;
        } return false;
        
        
    }
};
