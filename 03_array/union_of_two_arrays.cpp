// brute force approach- use set
//T.C is O(n1 log n1 + n2 log n2 + n1 + n2)
//S.C IS o(n1+n2) {set} + o(n1+n2) {to display result}
class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        set<int>st;
        st.insert(nums1.begin(), nums1.end());
        st.insert(nums2.begin(), nums2.end());
        return vector<int>(st.begin(), st.end());       
    }
};

// optimal approach
//TC = O(N1+N2) SC = O(N1+N2)
class Solution {
   public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int j = 0;
        vector<int> unionArr;
        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) {
                if (unionArr.size() == 0 || unionArr.back() != nums1[i]) {
                    unionArr.push_back(nums1[i]);
                }
                i++;
            } else if (nums1[i] > nums2[j]) {
                if (unionArr.size() == 0 || unionArr.back() != nums2[j]) {
                    unionArr.push_back(nums2[j]);
                }
                j++;
            }
        }
        while (j < n2) {
            if (unionArr.size() == 0 || unionArr.back() != nums2[j]) {
                unionArr.push_back(nums2[j]);
            }
            j++;
        }
        while (i < n1) {
            if (unionArr.size() == 0 || unionArr.back() != nums1[i]) {
                unionArr.push_back(nums1[i]);
            }
            i++;
        }
        return unionArr;
    }
};
