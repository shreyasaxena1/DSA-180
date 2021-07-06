class Solution
{
public:
    int t[100][100];

    int Solve(int arr[], int i, int j)
    {
        if (i >= j)
        {
            t[i][j] = 0;
            return 0;
        }

        if (t[i][j] != -1)
            return t[i][j];

        int ans = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            int temp_ans = Solve(arr, i, k) + Solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
            ans = min(ans, temp_ans);
        }

        return t[i][j] = ans;
    }

    int matrixMultiplication(int N, int arr[])
    {
        memset(t, -1, sizeof(t));
        return Solve(arr, 1, N - 1);
    }
};