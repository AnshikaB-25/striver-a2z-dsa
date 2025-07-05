// lower bound is  smallest index for which nums[index] >= target
//direct -- lb = lower_bound(nums.begin(), nums.end() , x) - nums.begin()
// for array use lower_bound(arr, arr+n , x) - arr
// TC - O(LOG N).... 
// SEARCH INSERT POSITION CODE IS SAME FOR SEARCH INSERT POSITION
int lowerBound(vector<int> &nums, int x) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();
        while (low <= high) {
             int mid = (low + high) / 2;
            if (nums[mid] >= x) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }

// upper bound smallest index for which nums[index]> target';
class Solution{
public:
    int upperBound(vector<int> &nums, int x){
        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();
        while (low <= high) {
             int mid = (low + high) / 2;
            if (nums[mid] > x) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};

// floor - largest index such that nums[index]<=target; and CEIL -smallest index for which nums[index] >= target
class Solution {
   public:
    int floor(vector<int> nums, int x) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] <= x) {
                ans = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return ans;
    }

    int ceil(vector<int> &nums, int x) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int f=floor(nums,x);
        int c = ceil(nums,x);
        return{nums[f],nums[c]};
    }
};
