//BRUTE FORCE....TC - O(n^3) *  LOG (no of unique triplets) 
// SC - 2* O( no of triplets)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>> st;
        int n = nums.size();
        for (int i = 0; i<n; i++){
            for (int j = i+1; j<n ; j++){
                for (int k = j+1; k<n; k++){
                    if ( nums[i]+nums[j]+nums[k]==0){
                        vector<int>temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
        
    }
};
// better using a set...TC - O(n^2 LOG K) ..... LOG K FOR INSERTION OF UNIQUE TRIPLETS IN SET...K IS NUMBER OF ELEMENTS IN HASH SET
// S.C - o(n) for hash and o(number of unique triplets)*2 for st and ans;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>> st;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            set<int> hash;
            for (int j = i + 1; j < n; j++) {
                int target = -(nums[i] + nums[j]);
                if (hash.find(target) == hash.end())
                    hash.insert(nums[j]);
                else {
                    hash.insert(nums[j]);
                    vector<int>temp={nums[i], nums[j], target};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
// OPTIMAL ...TC - N LOG N + N^2 
//
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i<n ; i++){
            if (i>0 && nums[i]==nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i]+ nums[j]+ nums[k];
                if(sum<0) j++;
                else if(sum>0 ) k--;
                else {
                    vector<int>temp = {nums[i] ,  nums[j] , nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;

                }
            }
        }
        return ans;
    }
};
};
