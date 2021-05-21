//TC : O(n2)
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> r(numRows);

        for (int i = 0; i < numRows; i++)
        {
            r[i].resize(i + 1);    // row elements = col number+1
            r[i][0] = r[i][i] = 1; // first and last element of each row is 1

            for (int j = 1; j < i; j++) //first to 2nd last col
            {
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
            }
        }
        return r;
    }
};