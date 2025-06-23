// brute force: TC O(N^3)
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int len = 0;
        int n = nums.size();
        for (int i = 0; i<n ; i++){
            for(int j = i; j<n; j++){
                long long sum = 0;
                for(int ka = i ; ka<=j; ka++){
                    sum+=nums[ka];
                }
                if (sum ==k){
                    len = max(len,j-i+1);
                }
            }
        } 
        return len;       
    }
};
// bRUTE FORCE BEST CASE as TC; O(N^2)
int longestSubarray(vector<int> &nums, int k){
        int len = 0;
        int n = nums.size();
        for (int i = 0; i<n ; i++){
            long long sum = 0;
            for(int j = i; j<n; j++){
                sum+= nums[j];
                if (sum ==k){
                    len = max(len,j-i+1);
                }
            }
        } 
        return len;       
    }
// better
int longestSubarray(vector < int > & nums, long long k) {
    int len = 0;
    int n = nums.size();
    long long sum = 0;
    map < long long, int > presum;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        if (sum == k) len = max(len, i + 1);
        long long rem = sum - k;
        if (presum.find(rem) != presum.end()) {
            int newlen = i - presum[rem];
            len = max(len, newlen);
        }
        if (presum.find(sum) == presum.end()) {
            presum[sum] = i;
        }

    }
    return len;
}

