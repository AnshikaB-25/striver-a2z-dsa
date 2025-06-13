// BRUTE FORCE - set 
//TC = n log n + n ..... SC = n
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set < int > st;
    for (int i = 0; i < nums.size(); i++) {
        st.insert(nums[i]);

    }
    int index = 0;
    for (auto it: st) {
        nums[index] = it;
        index++;
    }
    return index;
        
    }
};

// optimal approach : 2 pointer method... TC: O(N)...SC:0(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                nums[i+1] = nums[j];
                i++;
            }
            
        }
        return i+1;
    }
};
