//IMP- DONT PASS OUTPUT AS COPY IE WITH & CAUSE IT IS PASSED AS A COPY EVERYTIME SO IT WOULD HAVE THOSE VALUES ALREADY
class Solution {
public:
    void subsetsfind(vector<int>& nums, vector<int> output, int index,
                     vector<vector<int>>& ans) {
        if (index >= nums.size()) {
            ans.push_back(output);
            return;
        }
        subsetsfind(nums,output,index+1,ans);
        output.push_back(nums[index]);
        subsetsfind(nums,output,index+1,ans);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        subsetsfind(nums, output, index, ans);
        return ans;
    }
};
