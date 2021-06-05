//TC - 9*9*9..  9

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }

    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {

                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {

                        if (isValid(board, i, j, c))
                        {
                            board[i][j] = c;
                            if (solve(board) == true) //return true (outside one) when no empty place left
                                return true;
                            else
                                board[i][j] = '.'; //remove if not valid
                        }
                    }
                    return false; //when no value can be placed in this empty space
                }
            }
        }
        return true; //board is full
    }

    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == c)
                return false;
            if (board[i][col] == c)
                return false;
            if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == c)
                return false;
        }
        return true;
    }
};
