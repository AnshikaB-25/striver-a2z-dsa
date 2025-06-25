// brute force: O(n^3)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i<n ; i++){
            for(int j = i ; j<n; j++){
                int sum = 0;
                for(int x = i; x <=j ; x++){
                    sum += nums[x];
                }
                if(sum==k) count++;
            }
        }
        return count;
    }
};
