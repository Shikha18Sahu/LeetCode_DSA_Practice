class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int smallest = INT_MAX;  
        int n = prices.size(); 
        int profit = 0; 
        for(int i =0; i<n; i++){
            smallest = min(smallest, prices[i]);
            profit = max(prices[i]-smallest, profit); 
        }
        return profit; 
    }
};