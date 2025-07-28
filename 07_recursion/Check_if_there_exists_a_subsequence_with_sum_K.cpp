class Solution {
   public:
    bool subsequence(vector<int>& nums, int index, int variable_sum, int k) {
        if (index == nums.size()) {
            if (variable_sum == k) {
                return true;
            }
            return false;
        }
        if (subsequence(nums, index + 1, variable_sum, k) == true) return true;
        variable_sum += nums[index];
        if (subsequence(nums, index + 1, variable_sum, k) == true) return true;
        return false;
    }
    bool checkSubsequenceSum(vector<int>& nums, int k) {
        int index = 0;
        int variable_sum = 0;
        return subsequence(nums, 0, 0, k);
    }
};
