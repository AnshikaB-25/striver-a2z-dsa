//BRUTE FORCE.... T.C - O(n^2)..... S.C - O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i<n; i++){
            int count = 0;
            for (int j = 0; j<n ; j++){
                if (nums[j]==nums[i]) count++;
            }
            if (count > n/2) return nums[i];
        }
        return 0;
    }
};

// better approach: using hash map...TC - O(n log n) + O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mpp;
        for(int i = 0; i<n ; i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            if (it.second > n/2) return it.first;
        }
        return -1;
    }
};

//OPTIMAL APPROACH: MOORE'S VOTING ALGORITHM...TC - O(n).....SC - O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int element;
        for (int i = 0; i<nums.size(); i++){
           if(count == 0){
            element = nums[i]; count =1;
           }
           else if ( element==nums[i]){
            count++;
           }
           else count--;
        }
        return element;
    }
};
