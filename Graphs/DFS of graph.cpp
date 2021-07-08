// Complexity - same as BFS
class Solution {
public:
  void dfsUtil(int node, vector<int> adj[], vector<int> &vis,
               vector<int> &dfs) {
    dfs.push_back(node);
    vis[node] = 1;
    for (auto it : adj[node]) {
      if (!vis[it])
        dfsUtil(it, adj, vis, dfs);
    }
  }

  // Function to return a list containing the DFS traversal of the graph.
  vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> dfs;
    vector<int> vis(V, 0);
    dfsUtil(0, adj, vis, dfs);

    return dfs;
  }
};