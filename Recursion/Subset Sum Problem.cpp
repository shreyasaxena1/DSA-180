//TC - O(2^n log(2^n)) SC - O(2^n)

class Solution
{
public:
    void calculateSum(int ind, int sum, vector<int> &arr, int N, vector<int> &sumSubsets)
    {
        if (ind == N)
        {
            sumSubsets.push_back(sum);
            return;
        }

        calculateSum(ind + 1, sum, arr, N, sumSubsets);
        calculateSum(ind + 1, sum + arr[ind], arr, N, sumSubsets);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> sumSubsets;
        calculateSum(0, 0, arr, N, sumSubsets);
        sort(sumSubsets.begin(), sumSubsets.end());

        return sumSubsets;
    }
};
