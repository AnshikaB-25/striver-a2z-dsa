// find the middle element and its its left and right both are different then its the answer...otherwise understand that before the single element the other eleemnts are in(even,odd) pair 
//and after it they are in (odd,even)pair
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 1;
        int high =nums.size()-2;
        int n = nums.size();
        if(nums.size()==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        while(low<=high){
           int mid = (low+high)/2;
            if (nums[mid]!=nums[mid-1]  && nums[mid]!=nums[mid+1]){
                return nums[mid];
                break;
            }
            if(mid%2!=0){
                if(nums[mid-1]==nums[mid]){
                    low=mid+1;
                }
                else if(nums[mid+1]==nums[mid]) high = mid-1;
            }
            else{
                if(nums[mid-1]==nums[mid]){
                    high =mid-2;
                }
                else if(nums[mid+1]==nums[mid]){
                    low = mid+2;
                }
            }
        } return -1;

        
    }
};
