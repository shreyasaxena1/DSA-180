class Solution
{

public:
    vector<int> subsetSum(int arr[], int sum, int n)
    {
        bool t[n + 1][sum + 1]; // DP - matrix
        // initialization
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (i == 0)
                    t[i][j] = false;
                if (j == 0)
                    t[i][j] = true;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                    t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
                else
                    t[i][j] = t[i - 1][j];
            }
        }

        vector<int> v; // contains all subset sums possible with n elements
        for (int j = 0; j <= sum; j++)
            if (t[n][j] == true)
                v.push_back(j);

        return v;
    }

    int minDifference(int arr[], int n)
    {
        int range = 0;
        for (int i = 0; i < n; i++)
            range += arr[i];

        vector<int> v = subsetSum(arr, range, n);
        int mn = INT_MAX;
        for (int i = 0; i < v.size(); i++)
            mn = min(mn, abs(range - 2 * v[i]));

        return mn;
    }
};