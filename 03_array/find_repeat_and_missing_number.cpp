class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        vector<int>ans(2,0);
        for(int i = 1 ; i<= nums.size() ;i++ ){
            int count = 0;
            for(int j = 0 ; j< nums.size() ; j++){
                if(nums[j] == i) count++;
            }
            if(count == 2 ) ans[0] = i;
            if(count == 0) ans[1] = i;
        }
        return ans;
    }
};

// better soln...using a hash array
class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        vector<int>ans(2,0);
        int hash[nums.size()+1] = {0};
        for(int i = 0 ; i< nums.size() ;i++ ){
            hash[nums[i]]++;
        }
        for(int i = 1; i<= nums.size(); i++){
            if (hash[i]==2) ans[0] = i;
            if(hash[i]==0) ans[1] = i;
        }
        return ans;
    }
};
//OPTIMAL SOLN - USING MATH FIND X-Y AND X+Y ...USE LONG LONG FOR THE VARIABLES
vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int x; int y;
        int sum1=0; int sum2=0;
        int n = nums.size();
        for(int i = 0 ; i< nums.size(); i++){
            sum1+= nums[i];
            sum2+= nums[i] * nums[i];
        }
        int sum = n * (n+1) / 2;
        int sumnew = n* (n+1) * (2*n + 1) / 6;
        int diff = sum1-sum;
        int add = (sum2 - sumnew) / diff;
        x = (diff + add) /2;
        y = (add - diff) /2;
        return {x,y};
    }
