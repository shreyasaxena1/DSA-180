class Solution {
public:
  // Function to find minimum time required to rot all oranges.
  int orangesRotting(vector<vector<int>> &grid) {
    if (grid.empty())
      return 0;

    int n = grid.size(), m = grid[0].size();
    int qcnt = 0, torgs = 0, days = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] != 0)
          torgs++;
        if (grid[i][j] == 2)
          q.push({i, j});
      }
    }

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    while (!q.empty()) {
      int k = q.size();
      qcnt += k; // elemnt count that will be pushed in queue
      while (k--) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
          int nx = x + dx[i], ny = y + dy[i]; // new x,y coordinate to check
          if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1)
            continue;
          grid[nx][ny] = 2;
          q.push({nx, ny});
        }
      }
      if (!q.empty())
        days++;
    }

    return torgs == qcnt ? days : -1;
  }
};