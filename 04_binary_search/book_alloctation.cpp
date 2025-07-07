// DOUBT
class Solution {
   public:
    bool studentnums(vector<int> &nums, int mid, int m) {
        int stud = 1;
         int sum =0;
        for(int i = 0 ; i<nums.size(); i++){
            if(nums[i] + sum <= mid){
                sum+=nums[i];
            }
            else{
                stud++;
                sum = nums[i];
            }
        }
        if(stud<=m) return true;
        else return false;
    }
    int findPages(vector<int> &nums, int m) {
        if(m>nums.size()) return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end() , 0);
        while (low <= high) {
            int mid = (low + high) / 2;
            if (studentnums(nums, mid, m)) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return low;
    }
};
