// BRUTE FORCE: CREATE 2 DIFFERENT ARRAYS FOR POSITIVE AND NEGATIVE
//TC - O(n) + O(n/2)....SC - O(n)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>0) positive.push_back(nums[i]);
            else negative.push_back(nums[i]);
        }
        for(int i = 0 ; i< nums.size()/2 ; i++){
            nums[2*i] = positive[i];
            nums[2*i + 1] = negative[i];
        }
        return nums;
    }
};

// OPTIMAL SOLUTION: USING 2 DIFFERENT POINTERS AND 1 NEW ARRAY
// TC  - O(N) .....SC - 0(N)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       int positivee = 0;
       int negativee = 1;
       vector<int> ans(nums.size());
       for(int i = 0; i<nums.size(); i++){
        if(nums[i] > 0){
            ans[positivee] = nums[i];
            positivee += 2;
        }
        else {
            ans[negativee]=nums[i];
            negativee+=2;
        }
       }
       return ans;
    }
};
