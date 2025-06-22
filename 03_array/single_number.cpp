// brute force...TC O(n^2)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i =0; i<n;i++){
            int count = 0;
            for (int j = 0; j<n;j++){
                if(nums[i]==nums[j]) count++;
            }
            if (count==1) return nums[i];
        }
        return -1;
    }
};

// better: hash array TC - O(2n)....SC O(n)... alt is map too for -ve, 10^9 ELEMENTS
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int>hash(n+1,0);
        for (int i =0; i<n;i++){
            hash[nums[i]]++;
        }
        for (int i = 0; i<=n;i++){
            if (hash[i]==1) return i;
        }
        return -1;
    }
};

// optimal: XOR method...TC - O(n)....SC - O (1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int XOR1=0;
        for(int  i = 0; i<n ; i++){
            XOR1= XOR1^nums[i];
        }
        return XOR1;
        
    }
}; 
