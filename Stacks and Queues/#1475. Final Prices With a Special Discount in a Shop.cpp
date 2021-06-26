//Next smaller element
class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> discount(n, -1);
        stack<int> s;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top() > prices[i])
                s.pop();

            discount[i] = s.empty() ? prices[i] : prices[i] - s.top();

            s.push(prices[i]);
        }
        return discount;
    }
};