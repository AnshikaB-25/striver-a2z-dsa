// brute force : TC - O(n^2).... SC - O(N) WORST CASE TO STORE ANSWERS
class Solution {
   public:
    vector<int> leaders(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int truea = 1;
            int numb = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] > numb) {
                    truea = 0;
                    break;
                }
            }
            if (truea == 1) {
                ans.push_back(numb);
            }
        }
        return ans;
    }
};

// optimal... TC - O(n)
class Solution {
   public:
    vector<int> leaders(vector<int>& nums) {
        vector<int> ans;
        int maximum = INT_MIN;
        for (int i = nums.size()-1; i >= 0; i--) {
            if(nums[i]> maximum){
                ans.push_back(nums[i]);
                maximum = nums[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
