// sorting and inserting each element and then moving the i pointer to j so that there are no repetions or subset of a already present set...o(log n) + o(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int i = 0;
        int n = intervals.size();
        while ( i < n) {
            int start = intervals[i][0];
            int last = intervals[i][1];
            int j = i + 1;
            while (j < n && intervals[j][0] <= last) {
                last = max(last, intervals[j][1]);
                j++;
            }
            ans.push_back({start, last});
            i = j;
        }
        return ans;
    }
};

// optimal doubt 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            if (ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};
