//TC - O(n*Logn) SC-O(1)

class Solution
{
public:
    //Function to find minimum number of pages.
    int mininum(int arr[], int n)
    {
        int res = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < res)
                res = arr[i];
        }
        return res;
    }

    int sumOfArray(int arr[], int n)
    {
        int res = 0;
        for (int i = 0; i < n; i++)
            res += arr[i];
        return res;
    }
    bool isPossible(int arr[], int n, int barrier, int m)
    {
        int student = 1, pages = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > barrier)
                return false;
            if (arr[i] + pages > barrier)
            {
                student++;
                pages = arr[i];
            }
            else
                pages += arr[i];
        }
        if (student > m)
            return false;
        return true;
    }
    int findPages(int arr[], int n, int m)
    {
        if (n < m)
            return -1;
        int res = INT_MAX, low = mininum(arr, n), high = sumOfArray(arr, n);

        while (low <= high)
        {
            int mid = (low + high) >> 1;

            if (isPossible(arr, n, mid, m))
            {
                res = mid;
                high = mid - 1;
            }

            else
                low = mid + 1;
        }
        return res;
    }
};