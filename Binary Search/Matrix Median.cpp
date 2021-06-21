//Solved at interviewBit
//TC- O(32 nlogm) SC - O(1)

int getSmalllerAndEqualElement(vector<int> &rows, int mid)
{
    int low = 0;
    int high = rows.size() - 1;
    while (low <= high)
    {
        int md = (low + high) >> 1;
        if (rows[md] <= mid)
            low = md + 1;
        else
            high = md - 1;
    }
    return low;
}

int Solution::findMedian(vector<vector<int>> &A)
{
    int low = 1;
    int high = 1e9; //10^9
    int n = A.size();
    int m = A[0].size();

    while (low <= high)
    {
        int mid = (low + high) >> 1; //(low+high)/2
        int count = 0;
        for (int i = 0; i < n; i++)
            count += getSmalllerAndEqualElement(A[i], mid);
        if (count <= (n * m) / 2)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
