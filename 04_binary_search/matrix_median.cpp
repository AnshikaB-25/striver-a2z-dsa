// CONCEPT IS TO FIND THE NUMBER OF ELEMENTS SMALLER AND EQUAL TO A GIVEN NUMBER MID..... IF THE NO OF ELEMENTS IF GREATER THAN ROWS*COLS/2 THEN IT IS PROBABLE ANSWER...DO HIGH = MID -1;
//Example if rows*cols = 15 then 7 elements on left 7 on right and mid one is the median so for a number to be median it should have strictly greater than 7 elements on one lalf 
//TC - O(log2(max-min) * (rows*log2(cols)));
class Solution{
public:
int upperbound(vector<int>&matrix ,int mid1){
    int low = 0; int high = matrix.size()-1;
    while(low<=high){
        int mid =(low+high)/2;
        if(matrix[mid]> mid1) high = mid-1;
        else low = mid+1;
    }
    return low;
}
int findcount(vector<vector<int>>&matrix , int mid , int rows){
    int count = 0;
    for(int i = 0 ; i<rows ; i++){
        count+= upperbound(matrix[i], mid);
    }
    return count;
}
    int findMedian(vector<vector<int>>&matrix) {
        int low =INT_MAX; 
        int high = INT_MIN;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i = 0; i<rows ; i++){
            low = min(low , matrix[i][0]);
            high = max(high , matrix[i][cols-1]);
        }
        while(low<=high){
            int mid = (low+high)/2;
            int count = findcount(matrix,mid , rows);
            if(count > (rows*cols/2)) high = mid-1;
            else low = mid+1;

        }
        return low;
      
    }
};
