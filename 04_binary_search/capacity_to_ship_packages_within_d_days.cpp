// TC -O(n * log2(sum - max+1))
class Solution {
public:
    int maxele(vector<int>& weights) {
        int maxi = INT_MIN;
        for (int i = 0; i < weights.size(); i++) {
            maxi = max(maxi, weights[i]);
        }
        return maxi;
    }
    int totalsum(vector<int>& weights) {
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];
        }
        return sum;
    }
    int totaldays(vector<int>& weights, int mid) {
        int sum = 0;
        int days = 1;
        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] > mid) {
                sum = 0;
                days++;
            }
            sum += weights[i];
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = maxele(weights);
        int high = totalsum(weights);
        while (low <= high) {
            int mid = (low + high) / 2;
            int vals = totaldays(weights, mid);
            if (vals <= days)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
