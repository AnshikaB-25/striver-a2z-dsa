// TC - O( n * log2(max ele))
class Solution {
public:
    int maxele(vector<int>& bloomDay) {
        int maxi = INT_MIN;
        for (int i = 0; i < bloomDay.size(); i++) {
            maxi = max(maxi, bloomDay[i]);
        }
        return maxi;
    }
    int vals(vector<int>& nums , int mid){
        int ans = 0;
        for(int i = 0; i<nums.size() ;i++){
            ans += ((nums[i]+mid-1)/mid);
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = maxele(nums);
        while(low<=high){
            int mid = (low+high)/2;
            int ans = vals(nums , mid);
            if(ans<=threshold) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};
