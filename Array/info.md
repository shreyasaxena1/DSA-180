You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 
 
 class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size=prices.size();
        if(size<2)return 0;
        int buyPrice=prices[0],profit=0;
        for(int i=1;i<size;i++){
               buyPrice==min(buyPrice,prices[i])?profit=max(profit,prices[i]-buyPrice):buyPrice=prices[i];
        }
        return profit;
     }
};
