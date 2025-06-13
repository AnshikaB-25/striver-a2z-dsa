//T.C IS O(N)....SC is O(1)
// nums[n-1]=temp; it should be outside the foor loop
#include <bits/stdc++.h>

using namespace std;
void left_rotate(vector < int > & nums) {
   int temp=nums[0];
   int n = nums.size();
   for (int i = 1; i<nums.size(); i++){
       nums[i-1]=nums[i];
   }
   nums[n-1]=temp;
}

int main() {
    int n;
    cin >> n;
    vector < int > arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    left_rotate(arr);
    for (int i =0 ; i<n; i++){
        cout<<arr[i]<<" ";
    }
  // for rotating by n spaces left

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int d = k%n;
        vector<int>temp(d);
        for(int i = 0; i<d; i++){
            temp[i]= nums[i];
        }
        for(int i = d; i<n;i++){
            nums[i-d]=nums[i];
        }
        for (int i = n-d;i<n;i++){
            nums[i]=temp[i-(n-d)];
        }
        
    }
};
}
