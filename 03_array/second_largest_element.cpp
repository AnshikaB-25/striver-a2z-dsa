//brute force : QUICK SORT AND check from n-2 to 0 in array if... (i!= n-1)....ex (3 6 7 7 7 7 7)...T.C = n log n + n
// better approach: find largest and assume sec_large as -1...and find sec large....T.C O(2n) as 2 passes are required
class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int largest=nums[0];
        for (int i =0; i<nums.size(); i++){
            if (nums[i]>largest) largest=nums[i];
        }
        int sec_large = -1;
        for (int i=0;i<nums.size();i++){
            if(nums[i]>sec_large && nums[i] !=largest) sec_large=nums[i];
        }
        return sec_large;
      
    }
};

// better approach : TC = O{n)
#include <bits/stdc++.h>
using namespace std;
int second_largest (vector<int>nums){
    int largest=nums[0];
    int sec_large=INT_MIN;
    for (int i =0;i<nums.size();i++){
        if (nums[i]>largest) {
            sec_large = largest;
            largest= nums[i];
            
        }
        else if (nums[i]<largest && nums[i]>sec_large) sec_large=nums[i];
        
    }
    return sec_large;
}

int second_smallest(vector<int>nums){
    int smallest= nums[0];
    int sec_small=INT_MAX;
    for (int i =0; i<nums.size();i++){
        if (nums[i]<smallest){
            sec_small=smallest;
            smallest=nums[i];
        }
        else if (nums[i]>smallest&& nums[i]<sec_small) sec_small=nums[i];
    }
    return sec_small;
}
int main() {
	int n;
	cin>>n;
	vector<int> arr(n);
	for (int i=0;i<n;i++){
	    cin>>arr[i];
	}
	int ans1 = second_largest(arr);
	int ans2 = second_smallest(arr);
	cout<<ans1<<" "<<ans2;
}

