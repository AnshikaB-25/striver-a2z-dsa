//BRUTE FORCE: TC - O(n+m) + O(m)....FOR COPYING ELEMENTS IN NUM3 O(M).....WHILE LOOP EACH ELEMENT IS CHECKED ONCE SO O(m+n)
// SC - O(M)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3(nums1.begin() , nums1.begin()+m);
        int left = 0;
        int right = 0;
        int index = 0;
        while (left < m && right < n) {
            if (nums3[left] < nums2[right]) {
                nums1[index] = nums3[left];
                left++;
                index++;
            } else {
                nums1[index] = nums2[right];
                right++;
                index++;
            }
        }
        while(left<m){
            nums1[index++] = nums3[left++];
        }
         while(right<n){
            nums1[index++] = nums2[right++];
        }
    }

};

// OPTIMAL O(m+n)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m-1;
        int right = n-1;
        int newa = m+n -1;
        while (left>=0 && right>=0){
            if(nums1[left]>nums2[right]){
                nums1[newa]= nums1[left];
                newa--;
                left--;
            } else{
                nums1[newa]= nums2[right];
                newa--; right--;
            }
        }
        while(right>= 0){
            nums1[newa--]= nums2[right--];
        }
    }
};
