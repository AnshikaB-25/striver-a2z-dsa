// BRUTE FORCE CREATE A THIRD ARRAY AND FIND ITS MEDIAN IF SIZE OF THIRD ARRAY IS ODD THEN ELEMENT [SIZE/2].....AND IF ITS EVEN THEN ITS( EL[SIZE/2  -1] + EL[SIZE/2])  / 2 ....TC 0((N1+N2) AND SC..O(N1+N2)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int first = 0;
        int last = 0;
        vector<int> ans;
        while (first < n1 && last < n2) {
            if (nums1[first] < nums2[last]) {
                ans.push_back(nums1[first]);
                first++;
            } else {
                ans.push_back(nums2[last]);
                last++;
            }
        }
        while (first < n1) {
            ans.push_back(nums1[first]);
            first++;
        }
        while (last < n2) {
            ans.push_back(nums2[last]);
            last++;
        }
        int mid = (n1+n2)/2;
        if ((n1+n2)%2 != 0) {
            return ans[mid];
        }
        else{ 
            double val =(double) (ans[mid]+ans[mid-1])/(double)2;
            return val;
        }
        return -1;
    }
};
