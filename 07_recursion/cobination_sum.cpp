class Solution {
public:
    void subset(vector<int>& candidates, vector<vector<int>>& ans,
                vector<int>&output, int index, int sum, int target) {
        if (sum >= target || index>=candidates.size()) {
            if (sum == target)
                ans.push_back(output);
            return;
        }
        output.push_back(candidates[index]);
        subset(candidates,ans,output,index,sum + candidates[index],target);
        output.pop_back();
        subset(candidates,ans,output,index+1,sum,target);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        int sum = 0;
        subset(candidates, ans, output, 0, 0, target);
        return ans;
    }
};
