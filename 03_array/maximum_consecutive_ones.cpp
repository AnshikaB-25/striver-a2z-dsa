// optimal approach
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maximum = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                count += 1;
                maximum= max(count,maximum);
            } else {
                count = 0;
            }
        }
        return maximum;
    }
};
