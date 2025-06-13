//T.C O(n+d)....and S.C O(d)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int d = k%n;
        vector<int>temp(d);
        for(int i = 0; i<d; i++){
            temp[i]= nums[n-d+i];
        }
        for(int i = n-d-1; i>=0;i--){
            nums[i+d]=nums[i];
        }
        for (int i = 0;i<d;i++){
            nums[i]=temp[i];
        }
        
    }
};


// OPTIMISE SPACE COMPLEXITY
//T.C...O(2n)...SC...O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int d = k%n;
        reverse(nums.begin(),nums.end()-d);
        reverse(nums.end()-d,nums.end());
        reverse(nums.begin(),nums.end());
        
    }
};
