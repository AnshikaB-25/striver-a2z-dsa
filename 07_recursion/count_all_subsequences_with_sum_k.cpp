// TC - O(2^n)...SC - O(N)
class Solution{
    public:
    int subsequense(vector<int>&nums ,int index , int variable_sum , int k){
        int count = 0;
        if(index>=nums.size()){
            if(variable_sum==k) return 1;
            return 0;
        }
       int exclude = subsequense(nums,index+1,variable_sum,k);
        variable_sum+=nums[index];
        int include =subsequense(nums,index+1,variable_sum,k);
        return include+exclude;
    }    	
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	int index = 0;
        int variable_sum = 0;
        return subsequense(nums,0,0,k);
    }
};
