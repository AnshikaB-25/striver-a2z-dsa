// BRUTE FORCE: EVERY SUBARRAY GENERATION
// T.C IS ALMOST O(N^3)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxsum = 0;
        for(int i = 0; i<n;i++){
            for (int j = i; j<n; j++){
                int sum = 0; 
                for(int k = i; k<=j; k++){
                    sum+=nums[k];
                }
                maxsum=max(sum,maxsum);
            }
        }
        return maxsum;
        
    }
};

// BETTER IS BY REMOVING THE EXTRA LOOP
//TC - O(n^2)class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxsum = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                maxsum = max(sum, maxsum);
            }
        }
        return maxsum;
    }
};
// KADANE'S ALGORITHM : OPTIMAL....TC - O(n)....SC - O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum > max) {
                max = sum;
            }
            if (sum < 0)
                sum = 0;
        }
        return max;
    }
};
