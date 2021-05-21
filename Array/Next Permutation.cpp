class Solution
{
public:
    vector<int> reverse(vector<int> arr, int x)
    {
        int n = arr.size();
        int low = x, high = n - 1;
        while (low < high)
        {
            swap(arr[low], arr[high]);
            low++, high--;
        }
        return arr;
    }
    vector<int> nextPermutation(int n, vector<int> arr)
    {

        if (n == 0 || n == 1)
            return arr;
        int i, j;
        for (i = n - 2; i >= 0; i--)
        {
            if (arr[i] < arr[i + 1])
                break;
        }

        for (j = n - 1; j > i; j--)
        {
            if (arr[i] < arr[j])
                break;
        }
        //last permutation - change to first permutation
        if (i < 0)
        {
            arr = reverse(arr, 0);
        }
        else
        {
            swap(arr[i], arr[j]);
            arr = reverse(arr, i + 1);
        }
        return arr;
    }
};