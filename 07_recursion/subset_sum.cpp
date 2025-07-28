class Solution {
   public:
    void findsum(vector<int>& nums, vector<int>& ans, int sum, int index) {
        if (index == nums.size()) {
            ans.push_back(sum);
            return;
        }

        findsum(nums, ans, sum, index + 1);
        findsum(nums, ans, sum + nums[index], index + 1);
    }
    vector<int> subsetSums(vector<int>& nums) {
        vector<int> ans;
        int sum = 0;
        int index = 0;
        findsum(nums, ans, sum, index);
        return ans;
    }
    
};
