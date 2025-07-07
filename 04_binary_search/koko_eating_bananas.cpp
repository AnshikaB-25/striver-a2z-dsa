//Q875 TC - O(N * log(max(PILES[])))
class Solution {
public:
int maximaa(vector<int>& piles){
    int maxi=INT_MIN;
    for(int i = 0; i<piles.size(); i++){
        maxi = max(maxi, piles[i]);
    }
    return maxi;
}
    long long findingceil(vector<int>& piles, int mid) {
        int n = piles.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += ceil((double)piles[i]/(double)mid);
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxval = maximaa(piles);
        if (h == n)
            return maxval;
        int low = 1;
        int high = maxval; int ans=-1;
        while (low <= high) {
            int mid = (low + high) / 2;
            long long vals = findingceil(piles, mid);
            if (vals <=  1ll*h){
                ans = mid;
                 high = mid - 1;
            }  
            else
                low = mid + 1;
        }
        return ans;
    }
};
