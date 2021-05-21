//TC - O(n)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int buy = prices[0];
        int sell = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (prices[i] < buy)
            {
                buy = prices[i];
                sell = 0;
            }
            else if (prices[i] > sell)
                sell = prices[i];
        }

        if (sell < prices[n - 1])
            sell = prices[n - 1];
        return sell - buy;
    }
};