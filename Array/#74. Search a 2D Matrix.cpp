//Optimal for leetcode

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();    //row
        int m = matrix[0].size(); // columns
        int low = 0, high = (m * n) - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (target == matrix[mid / m][mid % m])
                return true;
            else if (target < matrix[mid / m][mid % m])
                high = mid - 1;

            else
                low = mid + 1;
        }
        return false;
    }
};

//Optimal for GFG

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();    //row
        int m = matrix[0].size(); // columns
        int row = 0, col = m - 1;
        if (target > matrix[n - 1][m - 1] || target < matrix[0][0])
            return false;
        while (row < n && col >= 0)
        {
            if (target > matrix[row][col])
                row++;
            else if (target < matrix[row][col])
                col--;
            else
                return true;
        }

        return false;
    }
};