// BRUTE FORCE....LINEAR SEARCH FOR EACH ELEMENT X THAT IF X+1 EXISTS THEN X+2 EXISTS..
// TC - O(n^2)
class Solution {
public:
bool linearSearch(vector<int>&nums , int x){
    for(int i = 0; i<nums.size(); i++){
        if(nums[i]== x) return true;
    }
    return false;
}
    int longestConsecutive(vector<int>& nums) {
        int length = 0;
        int n = nums.size();
        for(int i = 0; i<nums.size(); i++){
            int x = nums[i];
            int count = 1;
            while(linearSearch(nums,x+1)== true){
                x+=1;
                count+=1;
            }
            length = max(length,count);
        }
        return length;
    }
};

// better approach- SORT AND THEN CHECK IN THE JUST SMALLER NUMBER EXISTS
// T.C - N log N + O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n  = nums.size();
        int count = 0;
        int longest = 1;
        int lastsmall = INT_MIN;
        for(int i = 0; i<n ; i++){
            if(nums[i] == lastsmall+1){
                count+=1;
                lastsmall = nums[i];
            }
            else if(nums[i]!= lastsmall){
                lastsmall = nums[i];
                count = 1;
            }
            longest = max(count, longest);
        }
        return longest;
    }
};
// OPTIMAL SOLUTION.....USE SET
// TC  - O(3N) BEST CASE
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int count = 0;
        int longest = 1;
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                count = 1;
                int x = it;
                while (st.find(x + 1) != 0) {
                    count += 1;
                    x += 1;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};
