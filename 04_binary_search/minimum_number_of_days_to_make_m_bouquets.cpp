// in BS we can also use low as the minimum of that array....if we use that TC - O(N* log 2 (max-mini+1))
class Solution {
public:
    int maxele(vector<int>& bloomDay) {
        int maxi = INT_MIN;
        for (int i = 0; i < bloomDay.size(); i++) {
            maxi = max(maxi, bloomDay[i]);
        }
        return maxi;
    }
    bool checkbloom(vector<int>& bloomDay, int mid, int m, int k) {
        int count = 0;
        int ans = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                count++;
                if (count == k) {
                    ans++;
                    count = 0;
                }
            } else
                count = 0;
        }
        if (ans >= m)
            return true;
        else
            return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (1ll * m * k > n)
            return -1;
        int low = 1;
        int high = maxele(bloomDay);
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (checkbloom(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return low;
    }
};
