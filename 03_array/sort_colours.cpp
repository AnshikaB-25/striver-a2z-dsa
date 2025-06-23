// BRUTE FORCE - MERGE SORT
// Better: rearranging the whole array...TC - O(2N)....SC- O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int count_0 = 0;
        int count_1 = 0;
        int count_2 = 0;
        for (int i = 0; i<n; i++){
             if(nums[i]==0) count_0++;
             else if (nums[i]==1) count_1 ++;
             else count_2++;
        }
        for (int i = 0;i<count_0 ;i++) nums[i]=0;
        for (int i = count_0;i< count_0 + count_1 ;i++) nums[i]=1;
        for (int i = count_0 + count_1;i< count_0 + count_1 + count_2 ;i++) nums[i]=2;
    }
};

//OPTIMAL APPROACH- DUTCH NATIONAL FLAG ALGORITHM
//TC: O(N).... SC...O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
                mid++;
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
