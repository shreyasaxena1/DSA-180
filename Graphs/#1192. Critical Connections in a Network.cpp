class Solution {
public:
  void dfs(int node, int parent, vector<int> &vis, vector<int> &tin,
           vector<int> &low, vector<vector<int>> &g, int &timer,
           vector<vector<int>> &ans) {
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    for (auto it : g[node]) {
      if (it == parent)
        continue;
      if (!vis[it]) {
        dfs(it, node, vis, tin, low, g, timer, ans);
        low[node] = min(low[node], low[it]);
        if (low[it] > tin[node]) {
          vector<int> edge;
          edge.push_back(it);
          edge.push_back(node);
          ans.push_back(edge);
        }
      } else {
        low[node] = min(low[node], tin[it]);
      }
    }
  }

  vector<vector<int>> criticalConnections(int n,
                                          vector<vector<int>> &connections) {
    vector<vector<int>> ans;
    vector<int> tin(n, -1);
    vector<int> low(n, -1);
    vector<int> vis(n, 0);
    int timer = 0;
    vector<vector<int>> g(n, vector<int>());
    for (auto &conn : connections) {
      g[conn[0]].push_back(conn[1]);
      g[conn[1]].push_back(conn[0]);
    }
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        dfs(0, -1, vis, tin, low, g, timer, ans);
      }
    }
    return ans;
  }
};