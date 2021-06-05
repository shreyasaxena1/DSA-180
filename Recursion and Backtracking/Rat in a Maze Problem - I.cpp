//Solved at gfg
//TC - O(4^(n*m)) SC - m*n

class Solution
{
public:
    void getPaths(int i, int j, int n, vector<vector<int>> &m, vector<string> &ans, string move, vector<vector<int>> vis)
    {
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(move);
            return;
        }
        //Down
        if (i + 1 < n && m[i + 1][j] == 1 && !vis[i + 1][j])
        {
            vis[i][j] = 1;
            getPaths(i + 1, j, n, m, ans, move + 'D', vis);
            vis[i][j] = 0;
        }
        //Left
        if (j - 1 >= 0 && m[i][j - 1] == 1 && !vis[i][j - 1])
        {
            vis[i][j] = 1;
            getPaths(i, j - 1, n, m, ans, move + 'L', vis);
            vis[i][j] = 0;
        }
        //Right
        if (j + 1 < n && m[i][j + 1] == 1 && !vis[i][j + 1])
        {
            vis[i][j] = 1;
            getPaths(i, j + 1, n, m, ans, move + 'R', vis);
            vis[i][j] = 0;
        }
        //Up
        if (i - 1 >= 0 && m[i - 1][j] == 1 && !vis[i - 1][j])
        {
            vis[i][j] = 1;
            getPaths(i - 1, j, n, m, ans, move + 'U', vis);
            vis[i][j] = 0;
        }
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if (m[0][0] == 1)
            getPaths(0, 0, n, m, ans, "", vis);

        return ans;
    }
};
