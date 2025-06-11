//problem:  element that occurs the maximum number of times. highest occuring element in an array
//link:https://takeuforward.org/plus/dsa/problems/highest-occurring-element-in-an-array


class Solution {
   public:
    int mostFrequentElement(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }

        int max_freq = 0;
        int ans = nums[0];

        for (auto it : mpp) {
            int number = it.first;
            int count = it.second;
            if (count > max_freq) {
                max_freq = count;
                ans = number;
            } else if (count == max_freq && number < ans)
                ans = number;
        }
        return ans;
    }
};
added highest_occuring_element_in_array.cpp
