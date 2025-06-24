// brute force - 1) GENERATE ALL PERMUTATION IN SORTED MANNER
//2)LINEAR SEARCH FOR THE NUMBER USING LOOP
//3) NEXT ONE IN THE LIST IS NEXT PERMUTATION. IF THE ELEMENT IS LAST THEN FIRST ONE IS NEXT. 
// T.C - O(n! * n)

// BETTER APPROACH IN C++ USE next_permutation(nums.begin(), nums.end()) ...this is SQL
// OPTIMAL APPROACH... TC - 0(3n) AS R=THERE IS REVERSE TOO WORST CASE
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        for (int i = n - 2; i >= 0; i--) {   
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = n-1 ; i>index ; i--){
            if(nums[i]> nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
             
        }
        reverse(nums.begin() +index+1, nums.end());

    }
};
