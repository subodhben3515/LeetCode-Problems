class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minimum = prices[0];
        int profit = 0;
        for(int i =0 ; i < prices.size(); i++)
        {
            profit = max(profit, prices[i] - minimum);
            minimum = min(minimum, prices[i]);
        }
        return profit;
       /* int maxProfit =0 ;
       // int currentProfit  = 0;

        for(int i = 0; i < prices.size()-1; i++)
        {
            for(int j = i+1 ; j < prices.size(); j++)
            {
                //currentProfit = ;
                maxProfit = max(maxProfit, prices[j] - prices[i]);
            }
        }
       return maxProfit;*/ 
    }
};
