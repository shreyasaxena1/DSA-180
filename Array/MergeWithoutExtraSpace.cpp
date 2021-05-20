//Solved at GFG
// TC- O(nlogn) SC- O(1)

class Solution
{
public:
    int nextGap(int gap)
    {
        if (gap <= 1)
            return 0;

        return gap / 2 + gap % 2; //for talking ceiling value
    }

    //Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        int i, j, gap = m + n;
        for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
        {
            //Comparing in first array
            for (i = 0; i + gap < n; i++)
            {
                if (arr1[i] > arr1[i + gap])
                    swap(arr1[i], arr1[i + gap]);
            }

            //Comparing from both arrays
            for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)
            {
                if (arr1[i] > arr2[j])
                    swap(arr1[i], arr2[j]);
            }

            //Comparing from third array
            if (j < m)
            {
                for (j = 0; j + gap < m; j++)
                {
                    if (arr2[j] > arr2[j + gap])
                        swap(arr2[j], arr2[j + gap]);
                }
            }
        }
    }
};