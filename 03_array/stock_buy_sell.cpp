// brute force: 2 LOOP
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int pro = 0;
        for(int i = 0; i<n;i++){
            for(int j = i+1; j<n; j++){
                if(prices[j]> prices[i]){
                    int pro_1 = prices[j] - prices[i];
                    pro = max(pro,pro_1);
                }
                
            }
        }
        return pro;
        
    }
};

// optimal
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    
        int minPrice = INT_MAX;
        int max_pro = 0;
        for (int i = 0; i < prices.size(); i++) {
            minPrice = min (minPrice, prices[i]);
            max_pro = max (max_pro, prices[i]-minPrice); 
        }
        return max_pro;
    }
};
