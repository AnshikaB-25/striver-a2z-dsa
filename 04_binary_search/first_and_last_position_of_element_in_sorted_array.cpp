//tc - 2*logn.... USING LOWER BOUND AND UPPERBOUND-1
class Solution {
public:
    int lowerbound(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>= target){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    int upperbound(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]> target){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb= lowerbound(nums,target);
        int ub= upperbound(nums,target);
        if(lb==nums.size() || nums[lb]!= target) return {-1,-1};
        else return{lb , ub-1};
    }
};

// USIMG NORMAL BINARY SEARCH
class Solution {
public:
    int firstpos(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int first = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]== target){
                first = mid;
                high = mid-1;
            }
            else if(nums[mid]<target) low = mid+1;
            else high = mid-1;
        }
        return first;
    }
    int lastpos(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int last = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]== target){
                last = mid;
                low=mid+1;
            }
            else if( nums[mid]> target) high = mid-1;
            else low = mid+1;
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
       int first = firstpos(nums, target);
       int last = lastpos(nums,target);
       return{first,last};
    }
};
