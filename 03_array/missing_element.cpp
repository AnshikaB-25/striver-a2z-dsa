// brute force.... check if each number is present using 2 loops
// T.C - O(n^2) worst or hypothetical
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i <= n; i++) {
            int flag = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] == i) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                return i;
            }
        }
        return n;
    }
};

// better approach....use a hash array and check for hash array index = 0; T.C - O(N) + O(N).....SPACE COMPLEXITY 0(N+1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int>hash(n+1,0);
        for (int i = 0; i < n; i++) {
            hash[nums[i]] = 1;
        }
        for (int i = 0; i <= n; i++) {
            if (hash[i] == 0)
                return i;
        }
        return n;
    }
};

// optimal approach: sum method
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n*(n+1))/2;
        int suma=0;
        for (int i =0; i<n; i++){
            suma+=nums[i];
        }
        int numb;
        numb = sum - suma;
        return numb;
    }
};
