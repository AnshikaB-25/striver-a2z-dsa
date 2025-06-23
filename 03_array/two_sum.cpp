// BRUTE FORCE: TC - O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i<n; i++){
            for (int j = i+1; j<n; j++){
                if(nums[i]+nums[j]==target) {
                    return {i, j};

                }
            }
        }
        return {};
        
    }
};
// BETTER APPROACH...USE A HASH MAP....TC - O(N*LOG N )...SC - O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int , int> hash;
        for (int i = 0; i<n; i++){
            int initial = nums[i];
            int more = target - initial;
            if(hash.find(more)!=hash.end()){
                return {hash[more],i};
            }
            hash[initial]=i;
        }
        return {};  
    }
};
