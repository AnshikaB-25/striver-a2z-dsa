// works in sorted array ;  eliminates half of search area
//iterative approach... tc = o(log 2 (n))
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return mid;
                break;
            } else if (nums[mid] > target) {
                high = mid-1;
            }
            else low = mid+1;
        }
        return -1;
    }
};
