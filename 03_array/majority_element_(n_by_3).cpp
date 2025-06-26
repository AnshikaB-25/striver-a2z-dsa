class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) { 
        int n = nums.size();
        vector<int> ans;
        for (int  i = 0; i<n ; i++){
            int count = 0;
            for (int j = 0; j<n ; j++){
                if(nums[i]==nums[j]) count++;
            }
            if (count > n/3 && find(ans.begin(), ans.end() , nums[i])==ans.end())
             ans.push_back(nums[i]);
        }
        return ans;
        
    }
};
// BETTER
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        map<int,int>hash;
        int size = n/3 + 1;
        for(int i = 0; i<n ; i++){
            hash[nums[i]]++;
            if(hash[nums[i]]== size) ans.push_back(nums[i]);
            if (ans.size()==2) break;
        }
        return ans;      
    }
};
// OPTIMAL - MODIFIED MOORE'S VOTING AND CHECK FOR EDGE CASES LIKE ELE1 != ELE2 AND LASTLY MANUAL CHECK FOR COUNT
// TC - O(2N) .... SC- O(2) WHICH IS O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        int count1 = 0; int count2 = 0;
        int ele1= INT_MIN; int ele2 = INT_MIN;
        for(int i = 0; i<n ; i++){
            if(count1 ==0 && ele2!= nums[i]){
                ele1= nums[i]; count1++;
            }
            else if(count2 ==0 && ele1 != nums[i]){
                ele2= nums[i]; count2++;
            }
            else if(nums[i]==ele1) count1++;
            else if(nums[i]==ele2) count2++;
            else {count1--; count2 --;}
        }
        // manual check
        vector<int>ans;
        count1 = 0; count2 = 0;
        for(int i = 0; i<n ; i++){
            if (ele1 == nums[i]) count1++;
            if(ele2 == nums[i])count2++;
        }
        if (count1> n/3 ) ans.push_back(ele1);
        if(count2 > n/3) ans.push_back(ele2); 
        return ans;      
    }
};
