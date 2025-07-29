//In my initial code for Leetcode Q216 (Combination Sum III), I encountered a runtime error due to a heap-buffer-overflow. 
//The issue arose because I accessed nums[index] before checking whether the index was within bounds. Specifically, the line if(nums[index] > n || index >= nums.size()) return; 
//tries to access nums[index] even when index might already be equal to or greater than nums.size(), which causes undefined behavior and memory errors. 
//To fix this, I needed to first check if index is out of bounds before accessing any element at that index. The corrected condition is: if(index >= nums.size() || nums[index] > n) return;.
//This ensures safe memory access and prevents buffer overflows during recursion.
class Solution {
public:
    void findcombination(vector<vector<int>>& ans, vector<int>& output,
                         vector<int>& nums, int k, int n, int index) {

        if (k == 0) {
            if (n == 0) {
                ans.push_back(output);
            }
            return;

        }
        if(index>= nums.size() || nums[index]>n )return;
        output.push_back(nums[index]);
        findcombination(ans, output, nums, k - 1, n - nums[index], index + 1);
        output.pop_back();
        findcombination(ans,output,nums,k,n,index+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        findcombination(ans, output, nums, k, n, 0);
        return ans;
    }
};
