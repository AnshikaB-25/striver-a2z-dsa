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
// OPTIMAL: O(N) * LOG N (LOG N IS FOR MAP) 
class Solution{
public:
    int subarraysWithxorK(vector<int> &nums, int k) {
        int n = nums.size();
        int xr = 0;
        int count = 0;
        map<int,int>mpp;
        mpp[xr]=1;
        for(int i = 0; i<n ; i++){
           xr  =xr^nums[i];
           int rem = xr^k;
           count+=mpp[rem];
           mpp[xr]++;
            
        }
        return count;
        
    }
};
