//MY APPROACH 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int low = 0; int high = cols-1;
        int low1 = 0; int high1 = rows-1;
        while(low<=high && low1 <= high1){
            int mid = (low+high)/2; int mid1 = (low1 + high1 )/2;
            if(matrix[mid1][mid] == target) return true;
            else if(matrix[mid1][mid] < target) {
                if(matrix[mid1][high] < target) low1 = mid1 + 1;
                else low = mid+1;
            }
            else{
                if(matrix[mid1][low] > target) high1 = mid1-1;
                else high = mid-1;
            }
        }
        return false;
        
    }
};
//BRUTE FORCE - 2 FOR LOOP AND CHECK FOR EACH ELEMENT - O(m*n)
//BETTER - USE 1 FOR LOOP AND CHECK FOR ITS FIRST AND LAST ELEMENT IF ITS BETWEEN THEM THEN PERFORM A BINARY SEARCH
// OPTIMAL APPROACH -
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int low = 0;
        int high = rows*cols -1;
        while(low<=high){
            int mid = (low + high)/2;
            int ind1 = mid/cols;
            int ind2 = mid%cols;
            if(matrix[ind1][ind2] == target) return true;
            else if(matrix[ind1][ind2] > target) high = mid-1;
            else low = mid+1;
        }
        return false;
    }
};
