// TC - O(N* log2(max-min))
class Solution {
   public:
    bool mindist(vector<int> &nums, int mid, int k) {
        int first = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] - first) >= mid) {
                count++;
                first = nums[i];
            }
        }
        if (count >= k)
            return true;
        else
            return false;
    }
    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0;
        int high = nums[n - 1] - nums[0];
        if (k == 2) return high;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (mindist(nums, mid, k))
                low = mid + 1;
            else
                high = mid - 1;
        }
         return high;
    }
   
};
