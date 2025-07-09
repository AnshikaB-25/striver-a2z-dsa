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
// BETTER APPROACH: INSTEAD OF CREATING A THIRD ARRAY JUST CALCULATE THE INDEXES YOU NEED AND THEN FIND THAT INDEX OUT
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int m = n1 + n2;
        int ind1 = (m / 2) - 1;
        int ind2 = m / 2;
        int count = 0;
        int i = 0;
        int j = 0;
        int ele1 = -1;
        int ele2 = -1;
        while (i < n1 && j < n2) {
            if(nums1[i]< nums2[j]){
                if (count ==  ind1)
                    ele1 = nums1[i];
                if (count == ind2)
                    ele2 = nums1[i];
                count++;
                i++;
            }
            else{
                if (count == ind1)
                    ele1 = nums2[j];
                if (count == ind2)
                    ele2 = nums2[j];
                count++;
                j++;
            }
        }
        while (i < n1) {
            if (count ==  ind1)
                ele1 = nums1[i];
            if (count == ind2)
                ele2 = nums1[i];
            count++;
            i++;
        }
        while(j<n2){
             if (count ==  ind1)
                    ele1 = nums2[j];
                if (count == ind2)
                    ele2 = nums2[j];
                count++;
                j++;
        }
        if(m%2==1) return ele2;
        else return((double)(ele1 + ele2)/ (double)2);
    }
};
