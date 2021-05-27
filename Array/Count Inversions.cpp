//TC - O(N LOGN) SC - 0(N)
//Solved at gfg

class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long n)
    {
        long long temp[n];
        long long int ans = mergeSort(arr, temp, 0, n - 1);
        return ans;
    }
    long long int merge(long long arr[], long long temp[], long long low, long long mid, long long high)
    {

        long long int count = 0;
        long long i = low, j = mid, k = low;

        while (i <= (mid - 1) && j <= high)
        {
            if (arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else
            {
                temp[k++] = arr[j++];
                count = count + (long long int)(mid - i);
            }
        }

        while (i <= (mid - 1))
        {
            temp[k++] = arr[i++];
        }

        while (j <= high)
        {
            temp[k++] = arr[j++];
        }
        for (i = low; i <= high; i++)
            arr[i] = temp[i];

        return count;
    }
    long long int mergeSort(long long arr[], long long temp[], long long low, long long high)
    {
        long long int count = 0;
        long long mid;
        if (low < high)
        {
            mid = (low + high) / 2;

            count += mergeSort(arr, temp, low, mid);
            count += mergeSort(arr, temp, mid + 1, high);
            count += merge(arr, temp, low, mid + 1, high);
        }
        return count;
    }
};