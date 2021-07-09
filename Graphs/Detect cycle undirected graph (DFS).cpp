class Solution {
public:
  bool isCycleDfs(int node, int parent, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1;
    for (auto x : adj[node]) {
      if (vis[x] == 0) {
        if (isCycleDfs(x, node, vis, adj))
          return true;
      } else if (x != parent)
        return true;
    }
    return false;
  }
  // Function to detect cycle in an undirected graph.
  bool isCycle(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++) {
      if (!vis[i])
        if (isCycleDfs(i, -1, vis, adj))
          return true;
    }
    return false;
  }
};