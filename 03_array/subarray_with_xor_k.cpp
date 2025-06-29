// BRUTE IS OF LIKE 3 LOOPS....THIS IS BETTER....O(n^2)
class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i<n ; i++){
            int ans = 0;
            for(int j = i ; j<n ; j++){
                 ans = nums[j]^ans;
                 if(ans == k) count++;
            }
        }
        return count;
        
    }
};
