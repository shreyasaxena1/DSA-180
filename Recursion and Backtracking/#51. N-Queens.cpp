class Solution
{
public:
    void nQueensProblem(int col, int n, vector<string> &board, vector<vector<string>> &ans, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, vector<int> &leftRow)
    {

        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            //Check if they it is getting attacked
            if (leftRow[row] == 1)
                continue;
            if (upperDiagonal[n - 1 + row - col] == 1)
                continue;
            if (lowerDiagonal[row + col] == 1)
                continue;

            leftRow[row] = 1;
            upperDiagonal[n - 1 + row - col] = 1;
            lowerDiagonal[row + col] = 1;
            board[row][col] = 'Q'; //board[col] = row+1; (gfg)
            nQueensProblem(col + 1, n, board, ans, upperDiagonal, lowerDiagonal, leftRow);
        
           //pop out for recursion callbacks
            board[row][col] = '.';
            leftRow[row] = 0;
            upperDiagonal[n - 1 + row - col] = 0;
            lowerDiagonal[row + col] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);

        string s(n, '.');

        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }

        vector<int> upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0), leftRow(n, 0);

        nQueensProblem(0, n, board, ans, upperDiagonal, lowerDiagonal, leftRow);

        return ans;
    }
};