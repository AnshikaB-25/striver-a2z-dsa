 // only problem is when nums of low = mid = high so in that case increase low and decrease high and continue this until you reach a pt where they are unequal
//TC - AVERAGE O(LOG N) ...WORST O(n/2)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                return true;
                break;
            }
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low = low+1;
                high = high -1;
                continue;
            }
            if(nums[low]<= nums[mid]){
                if(nums[low]<=target && target<=nums[mid]){
                    high = mid-1;
                }
                else low = mid+1;
            }
            else{
                if(nums[mid]<=target && target<=nums[high]){
                    low = mid+1;
                }
                else high = mid-1;
            }

        

        }
        return false;
    }
};
