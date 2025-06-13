// brute force approach:  CREATING A NEW ARRAY
//T.C - O(2N) .....S.C O(N)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        for (int i = 0; i<n;i++){
            if (nums[i]!=0){
                temp.push_back(nums[i]);
            }
    
        }
        int j = temp.size();
        for(int i = 0; i<j;i++){
            nums[i]=temp[i];
        }
        for(int i = j; i<n;i++){
            nums[i]=0;
        }

        
    }
};


// two pointer approach:OPTIMAL SOLN
//TC: O(n).....SC O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j= 0;
        for (int i=0;i<n;i++){
            if (nums[i]!=0){
                nums[j]=nums[i];
                j++;
            }    
        }
        for (int i = j;i<n;i++){
            nums[i]=0;
        } 
        
    }
};
