//Brute force- quick sort and cout (n-1)....TC will be o(nlog n)
//optimal soln: TC...O(n)
class Solution {
public:
    int largestElement(vector<int>& nums) {
        int largest=nums[0];
        for (int i =0; i<nums.size(); i++){
            if (nums[i]>largest) largest=nums[i];
        }
        return largest;

    }
};
