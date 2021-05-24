int maxLen(int A[], int n)
{
    unordered_map<int, int> m;
    int sum = 0, maxi = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (sum == 0) //from 0 - i length has sum=0
            maxi = i + 1;
        else
        {
            if (m.find(sum) == m.end())
                m.insert({sum, i});
            else
                maxi = max(maxi, i - m[sum]);
        }
    }
    return maxi;
}